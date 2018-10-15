
#include "imageProcess.h"

cv::Mat imageProcess::resizeImage(cv::Mat& img){
	cv::resize(img, img, cv::Size(640, 480));
	return img;
}

cv::Mat imageProcess::histogramEqualization(cv::Mat& img){
	equalizeHist(img, img);
	return img;
}

cv::Mat imageProcess::toGray(cv::Mat& img){
	cvtColor(img, img, CV_BGR2GRAY);
	return img;
}

cv::Mat imageProcess::lowPassFilter(cv::Mat& img){
	blur(img, img, Size(3, 3));
	return img;
}
