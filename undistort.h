#include "opencv2\opencv.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include "calibration.h"

using namespace std;
using namespace cv;

class CUndistort
{
public:
    CUndistort(string srcImgPath, string calibResultPath, Mat camK, Mat camDiscoeff)
    {
        this->srcImgPath=srcImgPath;
        this->calibResultPath=calibResultPath;
        this->K = camK;
        this->discoeff= camDiscoeff;
    }
    ~CUndistort(){}

private:
    string srcImgPath;
    string calibResultPath;
    vector<Mat> srcImgList;
    vector<Mat> dsrImgList;
    Mat K;
    Mat R;
    Mat discoeff;

public:
    bool readParams();
    bool undistProcess();
    void run();

};