
#include "outputDisplay.h"


void outputDisplay::printImage(cv::Mat& img){
	cv::imshow("img", img);
	cv::waitKey(600);
}
void outputDisplay::printMessage(){
	// TODO
}
cv::Mat outputDisplay::markHuman(cv::Mat &img, cv::HOGDescriptor& hog) {
	std::vector<cv::Rect> found, found_filtered;
	hog.detectMultiScale(img, found, 0, cv::Size(8, 8), cv::Size(32, 32), 1.05, 2);
	size_t i, j;
	for (i = 0; i < found.size(); i++) {
		cv::Rect r = found[i];
		for (j = 0; j < found.size(); j++)
			if (j != i && (r & found[j]) == r)
				break;
		if (j == found.size())
			found_filtered.push_back(r);
	}

	for(auto i : found_filtered){
		std::cout << i << " ";
	}
	std::cout << std::endl;

	for (i = 0; i < found_filtered.size(); i++) {
		cv::Rect r = found_filtered[i];
		r.x += cvRound(r.width * 0.1);
		r.width = cvRound(r.width * 0.8);
		r.y += cvRound(r.height * 0.07);
		r.height = cvRound(r.height*0.8);
		rectangle(img, r.tl(), r.br(), cv::Scalar(rand() % 255, rand() % 255, rand() % 255), 3);
	}
	return img;
}
