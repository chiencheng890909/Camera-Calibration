#include <opencv2\opencv.hpp>
#include <string>
#include <iostream>
#include "calibration.h"
#include "undistort.h"

using namespace std;
using namespace cv;

int main()
{
    string patternImgPath = "C:/Users/1083310/Desktop/20211203/";
    string calibResultPath = "C:/Users/1083310/Desktop/stereo/stereo/";
    string srcImgPath="C:/Users/1083310/Desktop/20211203/1_R.jpg";
    Size boardSize=Size(9, 6);
    CCalibration calibration(patternImgPath, calibResultPath, boardSize);
    calibration.run();
    Mat cam = calibration.get_camK();
    Mat Discoeff = calibration.get_camDiscoeff();
    CUndistort undistort(srcImgPath, calibResultPath, cam, Discoeff);
    undistort.run();
}