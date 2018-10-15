
#include "perception.h"

// ---- perception
void perception::run(std::string imageName){
	// -- read image ----------------------------
	image = inputHandleObject.readImage(imageName); // color image
	// perceptionObject.image = perceptionObject.inputHandleObject.readImage("../gray_image.jpg"); // gray image

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

	

	// cout << "rows: " << resizedImage.rows << endl;
	// cout << "cols: " << resizedImage.cols << endl;


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

	//-------------------- High Pass Filter --------------------
	// TODO: this part not finish yet

	// Mat imageHighPass;
	// imageHighPass = image - imageLowPass;
	// imshow("imageHighPass", imageHighPass);

	// Mat imageEdge;
	// Canny(imageGray, imageEdge, 50, 150, 3);

	// Mat imageDraw;
	// imageEdge.convertTo(imageDraw, CV_8U);
	
	// imshow("imageEdge", imageEdge);
	
	// imageHighPass = image + imageEdge;
	// imageHighPass.convertTo(imageHighPass, CV_8U);
	// imshow("imageHighPass", imageHighPass);
	// ----------------------------------------------------------


	// // -- setting SVM classifier
	hogHumanDetectObject.setHogSVM(hogHumanDetectObject.hog);


	// // ----------------- Detect and Draw BB box -----------------
	imageResult = outputDisplayObject.markHuman(imageProcessed, hogHumanDetectObject.hog);
	// // ----------------------------------------------------------
	

	outputDisplayObject.printImage(imageResult);

	
	// imshow("imageResult", imageResult);
	// waitKey(0);
}
