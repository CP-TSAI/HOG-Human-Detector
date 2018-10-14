#ifndef INCLUDE_IMAGEPROCESS_H_
#define INCLUDE_IMAGEPROCESS_H_

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

class imageProcess{
private:

public: 
	cv::Mat resizeImage(cv::Mat& img); // unit test
	cv::Mat histogramEqualization(cv::Mat& img);
	cv::Mat toGray(cv::Mat& img); // unit test
	cv::Mat lowPassFilter(cv::Mat& img); // unit test
};

#endif    // INCLUDE_IMAGEPROCESS_H_
