#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat src, dst;
    src = imread("/home/zzh/图片/xiantiao.png");
    if(src.empty()) {
        cout << "can not load the image!" << endl;
        return -1;
    }
    imshow("src", src);

//    Mat kernel = getStructuringElement(MORPH_RECT, Size(23,23));
//    erode(src, dst, kernel);
//    dilate(dst, dst, kernel);
//    morphologyEx(src, dst, CV_MOP_OPEN, kernel);

//    dilate(src, dst, kernel);
//    erode(dst, dst, kernel);
//    morphologyEx(src, dst, CV_MOP_CLOSE, kernel);

    Mat kernel;
    kernel = getStructuringElement(MORPH_RECT, Size(1, src.rows / 16));
    cvtColor(src, dst, CV_RGB2GRAY);

    adaptiveThreshold(~dst, dst, 255, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 15, -2);// 二值化，输入图必须是单通道的
//    morphologyEx(dst, dst, CV_MOP_OPEN, kernel);
    erode(dst, dst, kernel);
    dilate(dst, dst, kernel);
//    bitwise_not(dst, dst);
    imshow("dst", dst);
    waitKey(0);
    return 0;
}