#ifndef INCLUDE_INPUTHANDLE_H_
#define INCLUDE_INPUTHANDLE_H_

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>


class inputHandle{
private:
	cv::Mat image; /* the input image */
	std::string errorMessage = "Could not open or find the image";
public: 
	bool isReadSuccessful = 0; // unit test
	cv::Mat readImage(std::string imgName); // unit test
	
};

#endif    // INCLUDE_INPUTHANDLE_H_
