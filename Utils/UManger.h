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

//*****************************************************************
	//�Զ��Աȶȵ���
	//************************************
	// Method:    autocontrost
	// FullName:  UManger::autocontrost
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: Mat matface
	// Author:    Haoyu_Zeng
	// Date:      2019/01/06 16:52
	//************************************
	int AutoControst(Mat matface);

protected:
	UManger();
	virtual ~UManger();
};

#endif // ZHY_UTILS_UMANAGER_H
