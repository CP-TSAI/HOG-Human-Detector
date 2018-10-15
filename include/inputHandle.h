#ifndef INCLUDE_INPUTHANDLE_H_
#define INCLUDE_INPUTHANDLE_H_

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

class inputHandle{
private:
	Mat image; /* the input image */
	string errorMessage = "Could not open or find the image";
public: 
	bool isReadSuccessful = 0; // unit test
	Mat readImage(string imgName); // unit test
	
};

#endif    // INCLUDE_INPUTHANDLE_H_
