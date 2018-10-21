#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat src = imread("/home/zzh/图片/reba.jpeg");
    if(!src.data) {
        cout << "can not load the image!" << endl;
        return -1;
    }
    imshow("src", src);

    Mat gray_src, dst;
    GaussianBlur(src, gray_src, Size(3,3), 0, 0);
    cvtColor(gray_src, gray_src, CV_RGB2GRAY);
    Laplacian(gray_src, dst, CV_16S, 3);
    convertScaleAbs(dst, dst);
    threshold(dst, dst, 0, 255, THRESH_OTSU | THRESH_BINARY);

    imshow("dst", dst);

    waitKey(0);
    return 0;
}