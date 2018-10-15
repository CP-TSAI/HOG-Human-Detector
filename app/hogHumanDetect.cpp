#include "hogHumanDetect.h"

HOGDescriptor& hogHumanDetect::setHogSVM(HOGDescriptor& hog){
	hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
	return hog;
}
