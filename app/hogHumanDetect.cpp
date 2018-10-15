#include "hogHumanDetect.h"

cv::HOGDescriptor& hogHumanDetect::setHogSVM(cv::HOGDescriptor& hog){
	hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
	return hog;
}
