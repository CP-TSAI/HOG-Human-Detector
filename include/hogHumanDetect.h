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

#ifndef INCLUDE_HOGHUMANDETECT_H_
#define INCLUDE_HOGHUMANDETECT_H_

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>




class hogHumanDetect{
 private:
 public:
    cv::HOGDescriptor hog;
    void setHogSVM(cv::HOGDescriptor& hog);
};

#endif    // INCLUDE_HOGHUMANDETECT_H_
