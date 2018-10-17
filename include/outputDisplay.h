/** @file outputDisplay.h
 *  @brief Visualize the detection result and save as image file
 *  @copyright (c) 2018 Chien-Te Lee, Chin-Po Tsai
 *
 *  This file contains definitions of class
 *  
 *  
 *  @author Chien-Te Lee, Chin-Po Tsai
 *  @date   10/16/2018
 *  
*/

#ifndef INCLUDE_OUTPUTDISPLAY_H_
#define INCLUDE_OUTPUTDISPLAY_H_

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>
#include <fstream>


/**
 *  @brief Class that shows the detection result.
*/
class outputDisplay{
private:
public:
	/**
      *   @brief  function for detection result
      *
      *   @param  image & file name
      *   @return the detected image
     */
	cv::Mat& outputImage(cv::Mat& img, std::string imageName);


	void printMessage(const cv::Rect& r, std::string imageName);


	cv::Mat markHuman(cv::Mat &img, cv::HOGDescriptor& hog, std::string imageName);

	std::ofstream writefile;
};

#endif    // INCLUDE_OUTPUTDISPLAY_H_
