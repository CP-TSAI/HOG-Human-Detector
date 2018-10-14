#ifndef INCLUDE_INPUTHANDLE_H_
#define INCLUDE_INPUTHANDLE_H_

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>

class inputHandle{
private:
	cv::Mat image; /* the input image */
	std::string errorMessage;
public: 
	bool isReadSuccessful; // unit test
	cv::Mat readImage(std::string imgName); // unit test
};

#endif    // INCLUDE_INPUTHANDLE_H_
