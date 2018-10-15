#include "inputHandle.h"

cv::Mat inputHandle::readImage(std::string imgName){
	image = cv::imread(imgName , CV_LOAD_IMAGE_COLOR);

	if(! image.data ) {
		std::cout << errorMessage << std::endl;
		return cv::Mat::zeros(cvSize(2, 2), CV_8UC3);
	}
	isReadSuccessful = 1;
	return image;
}
