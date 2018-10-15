#ifndef INCLUDE_OUTPUTDISPLAY_H_
#define INCLUDE_OUTPUTDISPLAY_H_

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;


class outputDisplay{
private:
public:
	cv::Mat& outputImage(Mat& img, string imageName);
	void printMessage(cv::Rect& r, string imageName);
	Mat markHuman(Mat &img, HOGDescriptor& hog, string imageName); // unit test
	ofstream writefile;
};

#endif    // INCLUDE_OUTPUTDISPLAY_H_
