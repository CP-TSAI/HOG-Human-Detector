#ifndef INCLUDE_OUTPUTDISPLAY_H_
#define INCLUDE_OUTPUTDISPLAY_H_

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>
#include <fstream>



class outputDisplay{
private:
public:
	cv::Mat& outputImage(cv::Mat& img, std::string imageName);
	void printMessage(cv::Rect& r, std::string imageName);
	cv::Mat markHuman(cv::Mat &img, cv::HOGDescriptor& hog, std::string imageName); // unit test
	std::ofstream writefile;
};

#endif    // INCLUDE_OUTPUTDISPLAY_H_
