#ifndef INCLUDE_PERCEPTION_H_
#define INCLUDE_PERCEPTION_H_


#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>

#include "inputHandle.h"
#include "imageProcess.h"
#include "hogHumanDetect.h"
#include "outputDisplay.h"

using namespace std;
using namespace cv;

class perception{
private:


public:
	void run(string imageName); // later
	void outputInfo(); // send message to other module
	inputHandle inputHandleObject; 
	hogHumanDetect hogHumanDetectObject;
	imageProcess imageProcessObject;
	outputDisplay outputDisplayObject;
	Mat image; 
	Mat imageResized;
	Mat imageLowPass;
	Mat imageGray;
	Mat imageHistogramEqualization;
	Mat imageProcessed; // rgb or gray
	Mat imageResult;
	bool isGray = 0;
};

#endif    // INCLUDE_PERCEPTION_H_
