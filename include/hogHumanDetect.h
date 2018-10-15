#ifndef INCLUDE_HOGHUMANDETECT_H_
#define INCLUDE_HOGHUMANDETECT_H_

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;


class hogHumanDetect{
private:

public:
	HOGDescriptor hog;
	HOGDescriptor& setHogSVM(HOGDescriptor& hog);
};

#endif    // INCLUDE_HOGHUMANDETECT_H_
