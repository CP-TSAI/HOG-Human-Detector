/** @file imageProcess.cpp
 *  @brief Implementation of class imageProcess methods
 *  @copyright (c) 2018 Chien-Te Lee, Chin-Po Tsai
 *  @author Chien-Te Lee, Chin-Po Tsai
 *  @date   10/16/2018
 *
 *  This file implements class imageProcess methods and functions.
 *  It contains algorithms of resizing, histogram equalization, 
 *  grayscaling, and low-pass filtering.
 *  
*/


#include "imageProcess.h"

/**
*   @brief This function resize the image
*   @param img is the input image to be resized
*   @return outImg is the resized image 
*/

cv::Mat imageProcess::resizeImage(const cv::Mat& img) {
    cv::Mat outImg;
    cv::resize(img, outImg, cv::Size(640, 480));
    return outImg;
}

/**
*   @brief This function does histogram equalizaiton to the image
*   @param img is the input image to be histogram equalized
*   @return outImg is the histogram equalized image 
*/
cv::Mat imageProcess::histogramEqualization(const cv::Mat& img) {
    cv::Mat outImg;
    equalizeHist(img, outImg);
    return outImg;
}

/**
*   @brief This function greyscales the image
*   @param img is the input image to be greyscaled
*   @return outImg is the greyscaled image 
*/
cv::Mat imageProcess::toGray(const cv::Mat& img) {
    cv::Mat outImg;
    cvtColor(img, outImg, CV_RGB2GRAY);
    return outImg;
}

/**
*   @brief This function do lowPassFiltering to the image
*   @param img is the input image to be blurred
*   @return outImg is the low-pass filtered image 
*/
cv::Mat imageProcess::lowPassFilter(const cv::Mat& img) {
    cv::Mat outImg;
    blur(img, outImg, cv::Size(3, 3));
    return outImg;
}
