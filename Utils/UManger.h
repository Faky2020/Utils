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
	int FastColorReduce(Mat& image, int div);

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

	//*************face���*************
	//���������㣬��68�������������д�뵽txt��
	//int FacesPoints(Mat& img);

	//*****************************************��Ʒ���*****************************************
	//���ñ��,�����ͼƬ��ñ�ӵ�ͼƬ��������Ľ���ñ��λ�ò�׼ȷ
	int AddHat(Mat& img);

	//����۾��������ͼƬ���۾���ͼƬ��������Ľ����۾�λ�û�׼ȷ
	int AddGrasses(Mat& img);

	//*****************************************�˾����*****************************************
	//��ӿ�ͨ�˾�
	int CartoonFilter(Mat& img);

	//��ӻ����˾�
	int NostalgicFilter(Mat& img);

	//��ӻ����˾�
	int WaveFilter(Mat& img, const int& level);

	//�ͻ��˾�
	int OilPaintFilter(Mat& img, const int& smoothness, const int& bucketSize);

	//*****************************************ͼƬ���*****************************************
	//����ͼƬ��ӣ��ֱ���������ͼƬ�����һ�źϳɵĽ��
	int PicAddPic(Mat& img1, Mat& img2, Mat& result);
	
	//����ͼƬ������ֱ���������ͼƬ�����һ�źϳɵĽ����img1�Ǳ�����
	int PicSubPic(Mat& img1, Mat& img2, Mat& result);
    
	//����ͼƬ��ӣ��ֱ���������ͼƬ�����һ�źϳɵĽ��
	int PicMulPic(Mat& img1, Mat& img2, Mat& result);
	
	//����ͼƬ��ӣ��ֱ���������ͼƬ�����һ�źϳɵĽ����img1�Ǳ�����
	int PicDivPic(Mat& img1, Mat& img2, Mat& result);

	//�Զ���ƽ�⣬����ͼƬ
	int WhiteBalance(Mat& img);

	//*************��ɫ�ռ�ת��*************


	//*****************************************�������*****************************************
	//�������ͼƬ�����Ӹ�˹����
	int AddGaussianNoise(Mat& img);

	//�������ͼƬ�����ӽ�������
	int AddSaltPepperNoise(Mat& img);

	//*****************************************�������*****************************************
	
	//���ļ�·���е���ƵתΪͼƬ����Ҫ������Ƶ��ַ��ͼƬ��ַ
	int VideoToPic(string VideoPath, string PicPath, double totalFrameNumber);

	//���ļ�·���е�ͼƬ�ϳ���Ƶ����Ҫ����ͼƬ��ַ����Ƶ��ַ���ߺͿ���Ƶ��ַ��ȷ����׺
	int PicToVideo(string PicPath, string VideoPath, int height, int width);

	//�����޸��ļ����ڵ�ͼƬ��������ͼƬ��ַ�����ͼƬ��ַ
	int RenamePic(string InPath, string OutPath);

	//*****************************************UI���*****************************************
	
	//UIͼƬ���
	int UI_Img(bool& use_img);

	//UI��Ƶ���
	int UI_Camera(bool& use_camera);


protected:
	UManger();
	virtual ~UManger();
};

#endif // ZHY_UTILS_UMANAGER_H
