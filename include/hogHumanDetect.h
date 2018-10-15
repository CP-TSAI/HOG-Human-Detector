#ifndef INCLUDE_HOGHUMANDETECT_H_
#define INCLUDE_HOGHUMANDETECT_H_

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>



class hogHumanDetect{
private:

public:
	cv::HOGDescriptor hog;
	void setHogSVM(cv::HOGDescriptor& hog);
};

#endif    // INCLUDE_HOGHUMANDETECT_H_
