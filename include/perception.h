/** @file perception.h
 *  @brief Pipeline controller for human detection
 *  @copyright (c) 2018 Chien-Te Lee, Chin-Po Tsai
 *
 *  This file contains definitions of class for perception
 *  
 *  
 *  @author Chien-Te Lee, Chin-Po Tsai
 *  @date   10/16/2018
 *  
*/

#ifndef INCLUDE_PERCEPTION_H_
#define INCLUDE_PERCEPTION_H_


#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "inputHandle.h"
#include "imageProcess.h"
#include "hogHumanDetect.h"
#include "outputDisplay.h"

/**
 *  @brief Class that does process controll
*/
class perception{
 private:
 public:
    void run(std::string imageName);
    void outputInfo();
    inputHandle inputHandleObject;
    hogHumanDetect hogHumanDetectObject;
    imageProcess imageProcessObject;
    outputDisplay outputDisplayObject;
    cv::Mat image;
    cv::Mat imageResized;
    cv::Mat imageLowPass;
    cv::Mat imageGray;
    cv::Mat imageHistogramEqualization;
    cv::Mat imageProcessed;
    cv::Mat imageResult;
    bool isGray = 0;
};

#endif    // INCLUDE_PERCEPTION_H_
