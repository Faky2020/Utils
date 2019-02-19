#ifndef ZHY_UTILS_UTILS_H
#define ZHY_UTILS_UTILS_H

#include "Common.h"

using namespace cv;
using namespace std;

//��ȡ��ǰ�汾
UTILS_API(string) GetCurrentVersion();

UTILS_API(int) ConvertRGB2Gray(const cv::Mat& imgRGB, cv::Mat& imgGray);

UTILS_API(int) FastColorReduce(Mat& image,int div);

UTILS_API(int) ContrastAndBright(Mat& src_image, Mat& dst_image, const double alpha, const double beta);


//*****************************************������*****************************************

UTILS_API(int) RGBSkin(Mat& img);

UTILS_API(int) EllipseSkin(Mat& img);

UTILS_API(int) YCrCbOtusSkin(Mat& img);

UTILS_API(int) YCrCbSkin(Mat& img);

UTILS_API(int) HSVSkin(Mat& img);

//face���

//UTILS_API(int) FacesPoints(Mat& img);

//*****************************************��Ʒ���*****************************************

UTILS_API(int) AddHat(Mat& img);

UTILS_API(int) AddGrasses(Mat& img);

//*****************************************�˾����*****************************************

UTILS_API(int) CartoonFilter(Mat& img);

UTILS_API(int) NostalgicFilter(Mat& img);

UTILS_API(int) WaveFilter(Mat& img,const int& level);

UTILS_API(int) OilPaintFilter(Mat& img,const int& smoothness,const int& bucketSize);
//����
//UTILS_API(int) AddRandom(Mat& img);


//*****************************************ͼƬ���*****************************************
UTILS_API(int) PicAddPic(Mat& img1, Mat& img2, Mat& result);

UTILS_API(int) PicSubPic(Mat& img1, Mat& img2, Mat& result);

UTILS_API(int) PicMulPic(Mat& img1, Mat& img2, Mat& result);

UTILS_API(int) PicDivPic(Mat& img1, Mat& img2, Mat& result);

UTILS_API(int) WhiteBalance(Mat& img);


//*****************************************�������*****************************************

UTILS_API(int) AddGaussianNoise(Mat& img);

UTILS_API(int) AddSaltPepperNoise(Mat& img);


//*****************************************�������*****************************************

UTILS_API(int) VideoToPic(string VideoPath, string PicPath, double totalFremeNumber);

UTILS_API(int) PicToVideo(string PicPath, string VideoPath, int height, int width);

UTILS_API(int) RenamePic(string InPath, string OutPath);


//*****************************************UI���*****************************************

UTILS_API(int) UI_Img(bool& use_img);

UTILS_API(int) UI_Camera(bool& use_camera);

#endif//ZHY_UTILS_UTILS_H
