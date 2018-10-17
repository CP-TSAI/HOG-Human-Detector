/** @file hogHumanDetect.cpp
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

#include "hogHumanDetect.h"

void hogHumanDetect::setHogSVM(cv::HOGDescriptor& hog){
	hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
}
