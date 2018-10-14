#ifndef INCLUDE_PERCEPTION_H_
#define INCLUDE_PERCEPTION_H_

#include "inputHandle.h"
#include "imageProcess.h"
#include "hogHumanDetect.h"
#include "outputDisplay.h"

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
	bool isGray;
};

#endif    // INCLUDE_PERCEPTION_H_
