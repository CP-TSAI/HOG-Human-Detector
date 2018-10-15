#include "imageProcess.h"

cv::Mat imageProcess::resizeImage(cv::Mat& img){
	cv::Mat outImg;
	cv::resize(img, outImg, cv::Size(640, 480));
	return outImg;
}

cv::Mat imageProcess::histogramEqualization(cv::Mat& img){
	cv::Mat outImg;
	equalizeHist(img, outImg);
	return outImg;
}

cv::Mat imageProcess::toGray(cv::Mat& img){
	cv::Mat outImg;
	cvtColor(img, outImg, CV_RGB2GRAY);
	return outImg;
}

cv::Mat imageProcess::lowPassFilter(cv::Mat& img){
	cv::Mat outImg;
	blur(img, outImg, cv::Size(3, 3));
	return outImg;
}