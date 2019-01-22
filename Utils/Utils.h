#ifndef ZHY_UTILS_UTILS_H
#define ZHY_UTILS_UTILS_H

#include "Common.h"

using namespace cv;
using namespace std;

//��ȡ��ǰ�汾
UTILS_API(string) GetCurrentVersion();

//RGBת�Ҷ�ͼ�������ɫͼ������Ҷ�ͼ
UTILS_API(int) ConvertRGB2Gray(const cv::Mat& imgRGB, cv::Mat& imgGray);

//����ͼ�����أ����� .ptr �� * ++ �Լ�λ���� (continuous+channels)���ٶ����
UTILS_API(int) FastColorReduce(Mat& image,int div);

//�޸�ͼƬ�����ȺͶԱȶȣ����ù�ʽg(i,j) = ��*f(i,j)+�£���Ҫ����alpha��betaֵ
UTILS_API(int) ContrastAndBright(Mat& src_image, Mat& dst_image, const double alpha, const double beta);

//���ļ�·���е���ƵתΪͼƬ����Ҫ������Ƶ��ַ��ͼƬ��ַ
UTILS_API(int) VideoToPic(string Video_Path, string Pic_Path, double totalFremeNumber);

//���ļ�·���е�ͼƬ�ϳ���Ƶ����Ҫ����ͼƬ��ַ����Ƶ��ַ���ߺͿ���Ƶ��ַ��ȷ����׺
UTILS_API(int) PicToVideo(string Pic_Path, string Video_Path,int height,int width);

//����ͼƬ��ӣ��ֱ���������ͼƬ�����һ�źϳɵĽ��
UTILS_API(int) PicAddPic(Mat& img1, Mat& img2, Mat& result);

//����ͼƬ��ӣ��ֱ���������ͼƬ�����һ�źϳɵĽ����img1�Ǳ�����
UTILS_API(int) PicSubPic(Mat& img1, Mat& img2, Mat& result);

//����ͼƬ��ӣ��ֱ���������ͼƬ�����һ�źϳɵĽ��
UTILS_API(int) PicMulPic(Mat& img1, Mat& img2, Mat& result);

//����ͼƬ��ӣ��ֱ���������ͼƬ�����һ�źϳɵĽ����img1�Ǳ�����
UTILS_API(int) PicDivPic(Mat& img1, Mat& img2, Mat& result);

/////////////////////////////////////////////////////////////////////
//�������ַ�ɫ��ⷽ��

//��һ�֣�����RGB color space
UTILS_API(int) RGBSkin(Mat& src_img,Mat& dst_img);

//�ڶ��֣�������Բģ�͵�Ƥ�����
UTILS_API(int) EllipseSkin(Mat& src_img, Mat& dst_img);

//�����֣�����YCrCb��ɫ�ռ�Cr����+Otus����ֵ�ָ�
UTILS_API(int) YCrCbOtusSkin(Mat& src_img, Mat& dst_img);

//�����֣�����YCrCb��ɫ�ռ�Cr��Cb��Χɸѡ
UTILS_API(int) YCrCbSkin(Mat& src_img, Mat& dst_img);

//�����֣�����HSV��ɫ�ռ�H��Χɸѡ��
UTILS_API(int) HSVSkin(Mat& src_img, Mat& dst_img);

/////////////////////////////////////////////////////////
//�������
//���ñ��
UTILS_API(int) AddHat(Mat& img);
//����۾�
UTILS_API(int) AddGrasses(Mat& img);
//��ӿ�ͨ�˾�
UTILS_API(int) CartoonFilter(Mat& img);
//��ӻ����˾�
UTILS_API(int) Nostalgic(Mat& img);
//����
//UTILS_API(int) AddRandom(Mat& img);

UTILS_API(int) WhiteBalance(Mat& img);

////////////////////////////////////////
//����
UTILS_API(int) AddGaussianNoise(Mat& img);
UTILS_API(int) AddSaltPepperNoise(Mat& img);

#endif//ZHY_UTILS_UTILS_H
