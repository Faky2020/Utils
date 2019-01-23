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

//***********************************************************************
	//RGBͼ��ת�Ҷ�ͼ
	//************************************
	// Method:    ConvertRGB2Gray
	// FullName:  UManger::ConvertRGB2Gray
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: const Mat & src
	// Parameter: Mat & gray
	// Author:    Haoyu_Zeng
	// Date:      2018/08/31 15:55
	//************************************
	int ConvertRGB2Gray(const Mat& src, Mat& gray);
	

//***********************************************************************
	//���ı���ͼ�񷽷�
	//************************************
	// Method:    FastColorReduce
	// FullName:  UManger::FastColorReduce
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: Mat & image
	// Parameter: int div
	// Author:    Haoyu_Zeng
	// Date:      2018/09/04 20:43
	//************************************
	int FastColorReduce(Mat& image,int div);
//**********************************************************************
	//�޸�ͼƬ�����ȺͶԱȶȣ���Ҫ����alphaֵ��betaֵ
	//************************************
	// Method:    ContrastAndBright
	// FullName:  UManger::ContrastAndBright
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: Mat & image
	// Parameter: Mat & new_image
	// Parameter: const double alpha
	// Parameter: const double beta
	// Author:    Haoyu_Zeng
	// Date:      2018/09/05 21:04
	//************************************
	int ContrastAndBright(Mat& src_image, Mat& dst_image, const double alpha, const double beta);

//*****************************************************************
	//����Ƶ�ó�һ֡һ֡��ͼƬ
	//************************************
	// Method:    VideoToPic
	// FullName:  UManger::VideoToPic
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: string Video_Path
	// Parameter: string Pic_Path
	// Parameter: double totalFrameNumber
	// Author:    Haoyu_Zeng
	// Date:      2018/09/19 14:54
	//************************************
	int VideoToPic(string Video_Path, string Pic_Path, double totalFrameNumber);

//*****************************************************************
	//���ļ�·��������ͼƬ�ϳ�һ����Ƶ
	//************************************
	// Method:    PicToVideo
	// FullName:  UManger::PicToVideo
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: string Pic_Path
	// Parameter: string Video_Path
	// Parameter: int height
	// Parameter: int width
	// Author:    Haoyu_Zeng
	// Date:      2018/09/20 22:52
	//************************************
	int PicToVideo(string Pic_Path, string Video_Path,int height,int width);

//****************************************************************
	//����ͼƬ�������
	//************************************
	// Method:    PicAddPic
	// FullName:  UManger::PicAddPic
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: Mat & img1
	// Parameter: Mat & img2
	// Parameter: Mat & result
	// Author:    Haoyu_Zeng
	// Date:      2019/01/09 15:50
	//************************************
	int PicAddPic(Mat& img1, Mat& img2, Mat& result);

//******************************************************
	//����ͼƬ���������img1�Ǳ�����
	//************************************
	// Method:    PicSubPic
	// FullName:  UManger::PicSubPic
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: Mat & img1
	// Parameter: Mat & img2
	// Parameter: Mat & result
	// Author:    Haoyu_Zeng
	// Date:      2019/01/09 15:52
	//************************************
	int PicSubPic(Mat& img1, Mat& img2, Mat& result);

//********************************************************
	//����ͼƬ���
	//************************************
	// Method:    PicMulPic
	// FullName:  UManger::PicMulPic
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: Mat & img1
	// Parameter: Mat & img2
	// Parameter: Mat & result
	// Author:    Haoyu_Zeng
	// Date:      2019/01/09 15:54
	//************************************
	int PicMulPic(Mat& img1, Mat& img2, Mat& result);

//***********************************************************
	//����ͼƬ�����img1�Ǳ�����
	//************************************
	// Method:    PicDivPic
	// FullName:  UManger::PicDivPic
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: Mat & img1
	// Parameter: Mat & img2
	// Parameter: Mat & result
	// Author:    Haoyu_Zeng
	// Date:      2019/01/09 15:54
	//************************************
	int PicDivPic(Mat& img1, Mat& img2, Mat& result);

////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//��������Ƥ����ⷽ��
//*****************************************************************
	//��һ��:����RGB color space���
	int RGBSkin(Mat& src_img,Mat& dst_img);
	//�ڶ���:������ԲƤ��ģ�͵�Ƥ�����
	int EllipseSkin(Mat& src_img, Mat& dst_img);
	//�����֣�����YCrCu��ɫ�ռ�Cr����+Otsu����ֵ�ָ�
	int YCrCbOtsuSkin(Mat& src_img, Mat& dst_img);
	//�����֣�����YCrCb��ɫ�ռ�Cr��Cb��Χɸѡ��
	int YCrCbSkin(Mat& src_img, Mat& dst_img);
	//�����֣�����HSV��ɫ�ռ�H��Χɸѡ��
	int HSVSkin(Mat& src_img, Mat& dst_img);

//*****************************************************************
	//�������
	//************************************
	// Method:    AddOrnament
	// FullName:  UManger::AddOrnament
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: Mat & src_img
	// Author:    Haoyu_Zeng
	// Date:      2019/01/11 17:47
	//************************************
	int AddHat(Mat& img);

	//************************************
	// Method:    AddGrasses
	// FullName:  UManger::AddGrasses
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: Mat & img
	// Author:    Haoyu_Zeng
	// Date:      2019/01/18 20:22
	//************************************
	int AddGrasses(Mat& img);

	//��ͨ�˾�
	//************************************
	// Method:    CartoonFilter
	// FullName:  UManger::CartoonFilter
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: Mat & img
	// Author:    Haoyu_Zeng
	// Date:      2019/01/18 20:22
	//************************************
	int CartoonFilter(Mat& img);

	//�����˾�
	//************************************
	// Method:    Nostalgic
	// FullName:  UManger::Nostalgic
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: Mat & img
	// Author:    Haoyu_Zeng
	// Date:      2019/01/18 20:22
	//************************************
	int Nostalgic(Mat& img);

	//************************************
	// Method:    AddRandom
	// FullName:  UManger::AddRandom
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: Mat & img
	// Author:    Haoyu_Zeng
	// Date:      2019/01/18 20:22
	//************************************
	//int AddRandom(Mat& img);

	//��ƽ��
	//************************************
	// Method:    WhiteBalance
	// FullName:  UManger::WhiteBalance
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: Mat & img
	// Author:    Haoyu_Zeng
	// Date:      2019/01/22 21:40
	//************************************
	int WhiteBalance(Mat& img);


///////////////////////////////////////////////
//�������
//add gaussian noise
	int AddGaussianNoise(Mat& img);
//add salt_noise
	int AddSaltPepperNoise(Mat& img);


/////////////////////////////////////////////
//face���



protected:
	UManger();
	virtual ~UManger();
};

#endif // ZHY_UTILS_UMANAGER_H
