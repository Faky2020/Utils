#ifndef ZHY_UTILS_UTILS_H
#define ZHY_UTILS_UTILS_H

#include "Common.h"

using namespace cv;
using namespace std;

//获取当前版本
UTILS_API(string) GetCurrentVersion();

//RGB转灰度图，输入彩色图，输出灰度图
UTILS_API(int) ConvertRGB2Gray(const cv::Mat& imgRGB, cv::Mat& imgGray);

//遍历图像像素，利用 .ptr 和 * ++ 以及位运算 (continuous+channels)，速度最快
UTILS_API(int) FastColorReduce(Mat& image,int div);

//修改图片的亮度和对比度，采用公式g(i,j) = α*f(i,j)+β，需要输入alpha和beta值
UTILS_API(int) ContrastAndBright(Mat& src_image, Mat& dst_image, const double alpha, const double beta);


//*****************************************检测相关*****************************************

//增加五种肤色检测方法
//第一种：基于RGB color space
UTILS_API(int) RGBSkin(Mat& img);

//第二种：基于椭圆模型的皮肤检测
UTILS_API(int) EllipseSkin(Mat& img);

//第三种：基于YCrCb颜色空间Cr分量+Otus法阈值分割
UTILS_API(int) YCrCbOtusSkin(Mat& img);

//第四种：基于YCrCb颜色空间Cr，Cb范围筛选
UTILS_API(int) YCrCbSkin(Mat& img);

//第五种：基于HSV颜色空间H范围筛选法
UTILS_API(int) HSVSkin(Mat& img);

//face相关
//人脸特征点，将68个特征点的坐标写入到txt中
//UTILS_API(int) FacesPoints(Mat& img);

//*****************************************饰品相关*****************************************
//添加帽子,输入的图片是帽子的图片，代码待改进，帽子位置不准确
UTILS_API(int) AddHat(Mat& img);
//添加眼镜，输入的图片是眼镜的图片，代码待改进，眼镜位置还准确
UTILS_API(int) AddGrasses(Mat& img);

//*****************************************滤镜相关*****************************************
//添加卡通滤镜
UTILS_API(int) CartoonFilter(Mat& img);
//添加怀旧滤镜
UTILS_API(int) NostalgicFilter(Mat& img);
//添加怀旧滤镜
UTILS_API(int) WaveFilter(Mat& img);
//测试
//UTILS_API(int) AddRandom(Mat& img);


//*****************************************图片相关*****************************************
//两张图片相加，分别输入两张图片，输出一张合成的结果
UTILS_API(int) PicAddPic(Mat& img1, Mat& img2, Mat& result);

//两张图片相减，分别输入两张图片，输出一张合成的结果，img1是被减数
UTILS_API(int) PicSubPic(Mat& img1, Mat& img2, Mat& result);

//两张图片相加，分别输入两张图片，输出一张合成的结果
UTILS_API(int) PicMulPic(Mat& img1, Mat& img2, Mat& result);

//两张图片相加，分别输入两张图片，输出一张合成的结果，img1是被除数
UTILS_API(int) PicDivPic(Mat& img1, Mat& img2, Mat& result);

//自动白平衡，输入图片
UTILS_API(int) WhiteBalance(Mat& img);

//UI滑动条修改亮度和对比度
//UTILS_API(int) Tb_ContrasAndBright(Mat& img);
//*****************************************噪音相关*****************************************
//在输入的图片上增加高斯噪音
UTILS_API(int) AddGaussianNoise(Mat& img);
//在输入的图片上增加椒盐噪声
UTILS_API(int) AddSaltPepperNoise(Mat& img);


//*****************************************工具相关*****************************************

//将文件路径中的视频转为图片，需要输入视频地址，图片地址
UTILS_API(int) VideoToPic(string VideoPath, string PicPath, double totalFremeNumber);

//将文件路径中的图片合成视频，需要输入图片地址，视频地址，高和宽，视频地址精确到后缀
UTILS_API(int) PicToVideo(string PicPath, string VideoPath, int height, int width);

//批量修改文件夹内的图片名，输入图片地址及输出图片地址
UTILS_API(int) RenamePic(string InPath, string OutPath);

//*****************************************UI相关*****************************************
UTILS_API(int) UI_Img(bool& use_img);

UTILS_API(int) UI_Camera(bool& use_camera);

#endif//ZHY_UTILS_UTILS_H
