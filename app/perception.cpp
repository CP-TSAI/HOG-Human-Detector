
#include "perception.h"

// ---- perception
void perception::run(std::string imageName){
	std::string folderName = "../imageData/Data/";
	image = inputHandleObject.readImage(folderName + imageName); 

	// check if read success
	if(!inputHandleObject.isReadSuccessful){
		std::cout << "ERROR!!!!!" << std::endl;
		return;
	}

	// check if is gray
	if(int(image.channels()) == 1){
		isGray = 1;
	}

	imageResized = imageProcessObject.resizeImage(image);

	if(isGray){ // do histogram equalization
		// --- Histogram Equalization
		imageHistogramEqualization = imageProcessObject.histogramEqualization(imageResized);
		imageProcessed = imageHistogramEqualization;
	}
	else{ // rgb, do low pass filter
		// --- Low Pass Filter
		imageLowPass = imageProcessObject.lowPassFilter(imageResized);
		imageProcessed = imageLowPass;
	}

	// -- setting SVM classifier
	hogHumanDetectObject.hog = hogHumanDetectObject.setHogSVM(hogHumanDetectObject.hog);

	imageResult = outputDisplayObject.markHuman(imageProcessed, hogHumanDetectObject.hog, imageName);
	outputDisplayObject.outputImage(imageResult, imageName);
}
