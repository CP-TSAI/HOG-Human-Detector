/** @file outputDisplay.h
 *  @brief Visualize the detection result and save as image file
 *  @copyright (c) 2018 Chien-Te Lee, Chin-Po Tsai
 *
 *  This file contains definitions of class for result visualization
 *  
 *  
 *  @author Chien-Te Lee, Chin-Po Tsai
 *  @date   10/16/2018
 *  
*/

#ifndef INCLUDE_OUTPUTDISPLAY_H_
#define INCLUDE_OUTPUTDISPLAY_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>



/**
 *  @brief Class that shows the detection result.
*/
class outputDisplay{
 public:
	/**
      *   @brief  save image to result files
      *
      *   @param  image & file name
      *   @return the detected image
     */
  cv::Mat& outputImage(cv::Mat& img, std::string imageName);


	/**
      *   @brief  print the detected message to terminal
      *
      *   @param  result vector & image name
      *   @return none
     */
  void printMessage(const cv::Rect& r, std::string imageName);


	/**
      *   @brief  draw the bounding box on image
      *
      *   @param  image file, hog detector, image name
      *   @return the image with bounding box
     */
  cv::Mat markHuman(cv::Mat &img, \
    cv::HOGDescriptor& hog, std::string imageName);

  std::ofstream writefile;    ///< txt writer

 private:
};

#endif    // INCLUDE_OUTPUTDISPLAY_H_
