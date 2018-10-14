#ifndef INCLUDE_OUTPUTDISPLAY_H_
#define INCLUDE_OUTPUTDISPLAY_H_

class outputDisplay{
private:
public:
	void printImage(Mat& img);
	void printMessage();
	Mat markHuman(Mat &img, HOGDescriptor& hog); // unit test
};

#endif    // INCLUDE_OUTPUTDISPLAY_H_
