/** @file inputHandle.h
 *  @brief Check read image status
 *  @copyright (c) 2018 Chien-Te Lee, Chin-Po Tsai
 *
 *  Check the status for reading image
 *  
 *  
 *  @author Chien-Te Lee, Chin-Po Tsai
 *  @date   10/16/2018
 *  
*/

#ifndef INCLUDE_INPUTHANDLE_H_
#define INCLUDE_INPUTHANDLE_H_

#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>


/**
 *  @brief Check the status
*/
class inputHandle{
 private:
    cv::Mat image;  ///< input image
    std::string errorMessage = "Could not open or find the image";
 public:
    bool isReadSuccessful = 0;  ///< read result
    cv::Mat readImage(std::string imgName);  ///< function for read image
};

#endif    // INCLUDE_INPUTHANDLE_H_
