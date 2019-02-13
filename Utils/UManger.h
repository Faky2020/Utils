/***********************************
 *
 * class:   classname
 * file UManger.h
 * ingroup GroupName
 * brief 
 * TODO: long description
 * author Haoyu_Zeng
 * version 1.0
 * date ���� 2018
 * Contact: 1150566379@qq.com
 *
 ***********************************/
#ifndef ZHY_UTILS_UMANAGER_H
#define ZHY_UTILS_UMANAGER_H

#include <math.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <cv.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>


#include "Singleton.h"

using namespace std;
using namespace cv;

class UManger : public Singleton<UManger>
{
	friend class Singleton<UManger>;

public:

	//RGBת�Ҷ�ͼ�������ɫͼ������Ҷ�ͼ
	int ConvertRGB2Gray(const Mat& src, Mat& gray);
	
	//����ͼ�����أ����� .ptr �� * ++ �Լ�λ���� (continuous+channels)���ٶ����
	int FastColorReduce(Mat& image,int div);

	//�޸�ͼƬ�����ȺͶԱȶȣ����ù�ʽg(i,j) = ��*f(i,j)+�£���Ҫ����alpha��betaֵ
	int ContrastAndBright(Mat& src_image, Mat& dst_image, const double alpha, const double beta);


	//*****************************************������*****************************************
										//��������Ƥ����ⷽ��
	//��һ��:����RGB color space���
	int RGBSkin(Mat& img);
	//�ڶ���:������ԲƤ��ģ�͵�Ƥ�����
	int EllipseSkin(Mat& img);
	//�����֣�����YCrCu��ɫ�ռ�Cr����+Otsu����ֵ�ָ�
	int YCrCbOtsuSkin(Mat& img);
	//�����֣�����YCrCb��ɫ�ռ�Cr��Cb��Χɸѡ��
	int YCrCbSkin(Mat& img);
	//�����֣�����HSV��ɫ�ռ�H��Χɸѡ��
	int HSVSkin(Mat& img);
										//face���
	//int FacesPoints(Mat& img);

	//*****************************************��Ʒ���*****************************************
	int AddHat(Mat& img);

	int AddGrasses(Mat& img);

	//*****************************************�˾����*****************************************
	int CartoonFilter(Mat& img);

	int NostalgicFilter(Mat& img);

	int WaveFilter(Mat& img);

	//*****************************************ͼƬ���*****************************************
	int PicAddPic(Mat& img1, Mat& img2, Mat& result);

	int PicSubPic(Mat& img1, Mat& img2, Mat& result);

	int PicMulPic(Mat& img1, Mat& img2, Mat& result);

	int PicDivPic(Mat& img1, Mat& img2, Mat& result);

	int WhiteBalance(Mat& img);

	//Tb means Trackbar
	//int Tb_ContrasAndBright(Mat& img);

	//*****************************************�������*****************************************
	int AddGaussianNoise(Mat& img);

	int AddSaltPepperNoise(Mat& img);

	//*****************************************�������*****************************************
	int VideoToPic(string VideoPath, string PicPath, double totalFrameNumber);
	
	int PicToVideo(string PicPath, string VideoPath, int height, int width);

	int RenamePic(string InPath, string OutPath);

	//*****************************************UI���*****************************************
	int UI_Img(bool& use_img);
	
	int UI_Camera(bool& use_camera);



protected:
	UManger();
	virtual ~UManger();
};

#endif // ZHY_UTILS_UMANAGER_H
