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

#ifndef INCLUDE_IMAGEPROCESS_H_
#define INCLUDE_IMAGEPROCESS_H_


#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>


class imageProcess{
 private:
 public:
    // ~imageProcess();
    cv::Mat resizeImage(const cv::Mat& img);
    cv::Mat histogramEqualization(const cv::Mat& img);
    cv::Mat toGray(const cv::Mat& img);
    cv::Mat lowPassFilter(const cv::Mat& img);
};

#endif    // INCLUDE_IMAGEPROCESS_H_
