/** @file TODO
 *  @brief TODO
 *  @copyright (c) 2018 Chien-Te Lee, Chin-Po Tsai
 *
 *  TODO
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



class inputHandle{
 private:
    cv::Mat image; /* the input image */
    std::string errorMessage = "Could not open or find the image";
 public:
    bool isReadSuccessful = 0;
    cv::Mat readImage(std::string imgName);
};

#endif    // INCLUDE_INPUTHANDLE_H_
