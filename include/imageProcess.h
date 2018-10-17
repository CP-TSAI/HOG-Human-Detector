/** @file imageProcess.h
 *  @brief tools for image process
 *  @copyright (c) 2018 Chien-Te Lee, Chin-Po Tsai
 *
 *  Set up every tool for basic image process
 *  
 *  
 *  @author Chien-Te Lee, Chin-Po Tsai
 *  @date   10/16/2018
 *  
*/

#ifndef INCLUDE_IMAGEPROCESS_H_
#define INCLUDE_IMAGEPROCESS_H_


#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>


/**
 *  @brief tools for image processing
*/
class imageProcess{
 private:
 public:
    cv::Mat resizeImage(const cv::Mat& img);  ///< change the image to 640*480
    ///< hostogram equalization tool
    cv::Mat histogramEqualization(const cv::Mat& img);
    ///< change image to gray scale
    cv::Mat toGray(const cv::Mat& img);
    ///< low pass filter for denoising
    cv::Mat lowPassFilter(const cv::Mat& img);
};

#endif    // INCLUDE_IMAGEPROCESS_H_
