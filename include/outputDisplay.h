#ifndef INCLUDE_OUTPUTDISPLAY_H_
#define INCLUDE_OUTPUTDISPLAY_H_

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

class outputDisplay{
private:
public:
	void printImage(cv::Mat& img);
	void printMessage();
	cv::Mat markHuman(cv::Mat &img, cv::HOGDescriptor& hog); // unit test
};

#endif    // INCLUDE_OUTPUTDISPLAY_H_
