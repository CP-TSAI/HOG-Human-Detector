#include "hogHumanDetect.h"

void hogHumanDetect::setHogSVM(HOGDescriptor& hog){
	hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
}
