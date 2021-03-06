#include "AKCalibr.h"

#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>

AKCalibr::AKCalibr() : mImgCount(0)
{
}

AKCalibr::~AKCalibr()
{
}

bool AKCalibr::Process(const std::vector<Mat>& imgList)
{
    if (imgList.size() < mConfig.imgCount)
    {
        cout << "Need more images!" << endl;
        return false;
    }

    if (mImgCount > mConfig.imgCount)
        return true;

    const Scalar RED(0, 0, 255);
    int baseLine = 6;
    Size textSize = cv::Size(70, 10);
    mImageSize = imgList[0].size();
    for (size_t i = 0; i < imgList.size(); ++i)
    {        
        if (imgList[i].empty())
            continue;
        
        cv::Mat image;
        if (imgList[i].channels() == 1)
        {
            cvtColor(imgList[i], image, CV_GRAY2RGB);
        }
        else
        {
            image = imgList[i];
        }

        vector<Point2f> pointBuf;
        bool found = findCirclesGrid(image, mConfig.boardSize, pointBuf, CALIB_CB_ASYMMETRIC_GRID);
        if (found && pointBuf.size() == mConfig.boardSize.width * mConfig.boardSize.height)
        {
            mImagePoints.push_back(pointBuf);
            if (++mImgCount == mConfig.imgCount)
                break;

            if (mConfig.showGridPoints)
            {                
                drawChessboardCorners(image, mConfig.boardSize, Mat(pointBuf), found);

                Point textOrigin(image.cols - 2 * textSize.width - 10, image.rows - 2 * baseLine - 10);
                string msg = format("%d/%d Undist", (int)mImagePoints.size(), mConfig.imgCount);
                putText(image, msg, textOrigin, 1, 1, RED);

                imshow("Image View", image);
                waitKey(mConfig.waitTime);
            }
        }
    }  

    bool ret = Calibration(mImageSize, mImagePoints, mMatrix, mDistCoeffs);
    mImgCount = 0;
    mImagePoints.clear();

    if (ret && mConfig.showUndistorsed)
    {
        Mat view, rview, map1, map2;

        Mat newCamMat;
        fisheye::estimateNewCameraMatrixForUndistortRectify(mMatrix, mDistCoeffs, mImageSize, Matx33d::eye(), newCamMat, 1);
        fisheye::initUndistortRectifyMap(mMatrix, mDistCoeffs, Matx33d::eye(), newCamMat, mImageSize, CV_16SC2, map1, map2);

        for (size_t i = 0; i < imgList.size(); ++i)
        {
            if (imgList[i].empty())
                continue;

            imgList[i].copyTo(view);      
            remap(view, rview, map1, map2, INTER_LINEAR);
            imshow("Image View", rview);
            waitKey(mConfig.waitTime);            
        }
    }

    return ret;
}

void AKCalibr::CalcBoardCornerPositions(Size boardSize, float squareSize, vector<Point3f>& corners)
{
    corners.clear();
    for (int y = 0; y < boardSize.height; ++y)
    {
        float tmpY = y * squareSize * 0.5f;
        float tmpX = (y % 2 * 0.5f) * squareSize;        
        for (int x = 0; x < boardSize.width; ++x)
            corners.push_back(Point3f(tmpX + x * squareSize, tmpY, 0));
    }
}

double AKCalibr::ComputeReprojectionErrors(const vector<vector<Point3f> >& objectPoints
    , const vector<vector<Point2f> >& imagePoints, const vector<Mat>& rvecs, const vector<Mat>& tvecs
    , const Mat& cameraMatrix, const Mat& distCoeffs, vector<float>& perViewErrors)
{
    double totalErr = 0;
    size_t totalPoints = 0;    
    vector<Point2f> imagePoints2;
    perViewErrors.resize(objectPoints.size());
    for (size_t i = 0; i < objectPoints.size(); ++i)
    {
        fisheye::projectPoints(objectPoints[i], imagePoints2, rvecs[i], tvecs[i], cameraMatrix, distCoeffs);

        double err = norm(imagePoints[i], imagePoints2, NORM_L2);

        size_t n = objectPoints[i].size();
        perViewErrors[i] = (float)std::sqrt(err * err / n);
        totalErr += err * err;
        totalPoints += n;
    }

    return std::sqrt(totalErr / totalPoints);
}

bool AKCalibr::Calibration(const Size& imageSize, const vector<vector<Point2f>> imagePoints, Mat& cameraMatrix
    , Mat& distCoeffs, vector<Mat>& rvecs, vector<Mat>& tvecs, vector<float>& reprojErrs)
{
    cameraMatrix = Mat::eye(3, 3, CV_64F);
    int tmpFlag = fisheye::CALIB_FIX_SKEW | fisheye::CALIB_RECOMPUTE_EXTRINSIC;
    if (tmpFlag & CALIB_FIX_ASPECT_RATIO)
        cameraMatrix.at<double>(0, 0) = mConfig.aspectRatio;

    distCoeffs = Mat::zeros(4, 1, CV_64F);
    vector<vector<Point3f>> objectPoints(1);
    CalcBoardCornerPositions(mConfig.boardSize, mConfig.squareSize, objectPoints[0]);

    objectPoints.resize(imagePoints.size(), objectPoints[0]);

    Mat tmpRvecs, tmpTvecs;
    double rms = fisheye::calibrate(objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, tmpRvecs, tmpTvecs, tmpFlag);

    rvecs.reserve(tmpRvecs.rows);
    tvecs.reserve(tmpTvecs.rows);
    for (int i = 0; i < int(objectPoints.size()); ++i)
    {
        rvecs.push_back(tmpRvecs.row(i));
        tvecs.push_back(tmpTvecs.row(i));
    }

    cout << "*************************************" << endl;
    cout << "RMS : " << rms << endl;
    cout << "Matrix : " << cameraMatrix << endl;
    cout << "DistCoeffs : " << distCoeffs << endl;
    bool ret = checkRange(cameraMatrix) && checkRange(distCoeffs);

    double totalAvgErr = ComputeReprojectionErrors(objectPoints, imagePoints, rvecs, tvecs, cameraMatrix, distCoeffs, reprojErrs);
    cout << "Calibration " << (ret ? "ucceeded" : "ailed") << ". avg reprojection error = " << totalAvgErr << endl;
    cout << "-------------------------------------" << endl;

    return ret;
}

bool AKCalibr::Calibration(const Size& imageSize, const vector<vector<Point2f>>& imagePoints, Mat& cameraMatrix, Mat& distCoeffs)
{
    vector<Mat> rvecs, tvecs;
    vector<float> reprojErrs;

    return Calibration(imageSize, imagePoints, cameraMatrix, distCoeffs, rvecs, tvecs, reprojErrs);
}
