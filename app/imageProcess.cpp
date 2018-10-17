/** @file imageProcess.cpp
 *  @brief Implementation of class imageProcess methods
 *  @copyright (c) 2018 Chien-Te Lee, Chin-Po Tsai
 *
 *  This file implements class imageProcess methods and functions.
 *  
 *  
 *  @author Chien-Te Lee, Chin-Po Tsai
 *  @date   10/16/2018
 *  
*/


#include "imageProcess.h"

cv::Mat imageProcess::resizeImage(const cv::Mat& img) {
    cv::Mat outImg;
    cv::resize(img, outImg, cv::Size(640, 480));
    return outImg;
}

cv::Mat imageProcess::histogramEqualization(const cv::Mat& img) {
    cv::Mat outImg;
    equalizeHist(img, outImg);
    return outImg;
}

cv::Mat imageProcess::toGray(const cv::Mat& img) {
    cv::Mat outImg;
    cvtColor(img, outImg, CV_RGB2GRAY);
    return outImg;
}

cv::Mat imageProcess::lowPassFilter(const cv::Mat& img) {
    cv::Mat outImg;
    blur(img, outImg, cv::Size(3, 3));
    return outImg;
}
