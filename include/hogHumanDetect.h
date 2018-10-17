/** @file hogHumanDetect.h
 *  @brief Setup the detector parameter
 *  @copyright (c) 2018 Chien-Te Lee, Chin-Po Tsai
 *
 *  setup SVM parameter and declare detector
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



/**
 *  @brief Setup things for detector
*/
class hogHumanDetect{
 private:
 public:
    cv::HOGDescriptor hog;  ///< the hog detector
    void setHogSVM(cv::HOGDescriptor& hog);  ///< set up the parameter
};

#endif    // INCLUDE_HOGHUMANDETECT_H_
