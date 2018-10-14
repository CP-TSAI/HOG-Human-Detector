#ifndef INCLUDE_PERCEPTION_H_
#define INCLUDE_PERCEPTION_H_

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>

#include "inputHandle.h"
#include "imageProcess.h"
#include "hogHumanDetect.h"
#include "outputDisplay.h"

class perception{
private:


public:
	void run(std::string imageName); // later
	void outputInfo(); // send message to other module
	inputHandle inputHandleObject; 
	hogHumanDetect hogHumanDetectObject;
	imageProcess imageProcessObject;
	outputDisplay outputDisplayObject;
	cv::Mat image; 
	cv::Mat imageResized;
	cv::Mat imageLowPass;
	cv::Mat imageGray;
	cv::Mat imageHistogramEqualization;
	cv::Mat imageProcessed; // rgb or gray
	cv::Mat imageResult;
	bool isGray;
};

#endif    // INCLUDE_PERCEPTION_H_
