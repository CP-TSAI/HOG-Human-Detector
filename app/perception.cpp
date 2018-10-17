/** @file perception.cpp
 *  @brief Implementation of runing algorithm
 *  @copyright (c) 2018 Chien-Te Lee, Chin-Po Tsai
 *  @author Chien-Te Lee, Chin-Po Tsai
 *  @date   10/16/2018
 *  
 *      This file implements run method of perception class and realizes
 *      the hog human detect algorithm
 *
*/

#include "perception.h"

/**
*   @brief This function runs the hog human detect algorithm
*   @param imageName is the name of input image
*   @return none
*/
void perception::run(std::string imageName) {
    std::string folderName = "../imageData/Data/";

    cv::Mat image = inputHandleObject.readImage(folderName + imageName);

    ///< check the status
    if (!inputHandleObject.isReadSuccessful) {
        std::cout << "ERROR!!!!!" << std::endl;
        return;
    }

    ///< check if is gray
    if (int(image.channels()) == 1) {
        isGray = 1;
    }

    cv::Mat imageResized = imageProcessObject.resizeImage(image);

    ///< if: do histogram equalization || else: do low pass filter
    if (isGray) {
        imageHistogramEqualization = \
        imageProcessObject.histogramEqualization(imageResized);

        imageProcessed = imageHistogramEqualization;

        imageHistogramEqualization.release();
    } else {
        imageLowPass = imageProcessObject.lowPassFilter(imageResized);
        imageProcessed = imageLowPass;
        imageLowPass.release();
    }


    ///< setting SVM classifier
    hogHumanDetectObject.setHogSVM(hogHumanDetectObject.hog);

    ///< draw bounding box
    imageResult = outputDisplayObject.markHuman(imageProcessed, \
                                      hogHumanDetectObject.hog, imageName);

    ///< save and show image
    outputDisplayObject.outputImage(imageResult, imageName);

    image.release();
}
