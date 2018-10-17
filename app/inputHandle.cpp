/** @file inputHandle.cpp
 *  @brief This file reads image and return the input image
 *  @copyright (c) 2018 Chien-Te Lee, Chin-Po Tsai
 *  @author Chien-Te Lee, Chin-Po Tsai
 *  @date   10/16/2018
 *
 *      This file reads image and returns the read image
 *  
 */

#include "inputHandle.h"


/**
*   @brief This function reads image from dataset 
*   @param image stores input image
*   @param isReadSuccessful is the flag indicate whether read successfully
*   @return image returns the input image 
*/
cv::Mat inputHandle::readImage(std::string imgName) {
    image = cv::imread(imgName , CV_LOAD_IMAGE_COLOR);

    ///< return and print error message when read does not success
    if (!image.data) {
        std::cout << errorMessage << std::endl;
        return cv::Mat::zeros(cvSize(2, 2), CV_8UC3);
    }
    isReadSuccessful = 1;
    return image;
}
