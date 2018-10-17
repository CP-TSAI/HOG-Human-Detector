/** @file hogHumanDetect.cpp
 *  @brief Implement method to set the parmeters for SVM detector
 *  @copyright (c) 2018 Chien-Te Lee, Chin-Po Tsai
 *  @author Chien-Te Lee, Chin-Po Tsai
 *  @date   10/16/2018
 *  
 *  This file sets the parameters of SVM detector to the default
 *  value for human detection
 *   
*/

#include "hogHumanDetect.h"

/**
*   @brief This function sets the parmeters for SVM detector
*   @param hog is the input HOGDescriptor
*   @return none 
*/
void hogHumanDetect::setHogSVM(cv::HOGDescriptor& hog) {
    hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
}
