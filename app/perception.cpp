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


#include "perception.h"

void perception::run(std::string imageName) {
    std::string folderName = "../imageData/Data/";

    cv::Mat image = inputHandleObject.readImage(folderName + imageName);

    // check if read success
    if (!inputHandleObject.isReadSuccessful) {
        std::cout << "ERROR!!!!!" << std::endl;
        return;
    }

    // check if is gray
    if (int(image.channels()) == 1) {
        isGray = 1;
    }

    cv::Mat imageResized = imageProcessObject.resizeImage(image);

    // if: do histogram equalization || else: rgb, do low pass filter
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


    // -- setting SVM classifier
    hogHumanDetectObject.setHogSVM(hogHumanDetectObject.hog);

    imageResult = outputDisplayObject.markHuman(imageProcessed, \
                                      hogHumanDetectObject.hog, imageName);
    outputDisplayObject.outputImage(imageResult, imageName);

    image.release();
}
