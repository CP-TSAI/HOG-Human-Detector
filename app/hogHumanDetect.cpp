#include "hogHumanDetect.h"

void hogHumanDetect::setHogSVM(cv::HOGDescriptor& hog){
	hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
}
