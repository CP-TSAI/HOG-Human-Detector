/** @file outputDisplay.cpp
 *  @brief Implementation of output display methods
 *  @copyright (c) 2018 Chien-Te Lee, Chin-Po Tsai 
 *  @author Chien-Te Lee, Chin-Po Tsai
 *  @date   10/16/2018
 *
 *
 *  This file imputs output display methods, including storing output
 *  images, writing messages to texts, and drawing the bounding box
 *  for human.
 *
 * 
*/

#include "outputDisplay.h"
#include <iostream>


/**
*   @brief This function stores image to detected folder 
*   @param img is the image need to be stored
*   @param imageName is the name of stored image
*   @return img returns stored image 
*/
cv::Mat& outputDisplay::outputImage(cv::Mat& img, std::string imageName) {
    // cv::imshow("img", img);
    // cv::waitKey(700);
    std::string folderName = "../imageDetected/";
    cv::imwrite(folderName + imageName, img);
    return img;
}

/**
*   @brief This function prints bounding box message into textfile
*   @param Rect is the bounding box information
*   @param imageName is the name of input image
*   @return none 
*/
void outputDisplay::printMessage(const cv::Rect& r, std::string imageName) {
    auto height = r.br().y - r.tl().y;
    auto width = r.br().x - r.tl().x;

    cv::Rect* center = new cv::Rect();
    // cv::Rect center;

    center->x = (r.br().x + r.tl().x)/2;
    center->y = (r.br().y + r.tl().y)/2;

    std::cout << "height: " << height << "; width: " << width << std::endl;
    std::cout << "center: (" << center->x << ", " \
    << center->y << ")" << std::endl << std::endl;

    writefile << "imageName: " << imageName << std::endl;
    writefile << "height: " << height << "; width: " << width << std::endl;
    writefile << "center: (" << center->x << ", " \
    << center->y << ")" << std::endl << std::endl;

    delete center;
}

/**
*   @brief This function draws bounding box of detected humans
*   @param img is the input image
*   @param hog is the SVM HOGDescriptor
*   @param imageName is the name of input image
*   @return img is the image with bounding box 
*/
cv::Mat outputDisplay::markHuman(cv::Mat &img, \
    cv::HOGDescriptor& hog, std::string imageName) {

    std::vector<cv::Rect> found, found_filtered;
    hog.detectMultiScale(img, found, 0, \
        cv::Size(8, 8), cv::Size(32, 32), 1.05, 2);

    for (size_t i = 0; i < found.size(); i++) {
        cv::Rect r = found[i];
        size_t j = 0;
        for (j = 0; j < found.size(); j++)
            if (j != i && (r & found[j]) == r)
                break;
        if (j == found.size())
            found_filtered.push_back(r);
    }

    std::cout << "Result: " << found_filtered.size() \
        << " people detected!" << std::endl;

    for (size_t i = 0; i < found_filtered.size(); i++) {
        cv::Rect r = found_filtered[i];
        r.x += cvRound(r.width * 0.1);
        r.width = cvRound(r.width * 0.8);
        r.y += cvRound(r.height * 0.07);
        r.height = cvRound(r.height*0.8);
        rectangle(img, r.tl(), r.br(), \
            cv::Scalar(rand() % 255, rand() % 255, rand() % 255), 3);

        printMessage(r, imageName);
    }

    found.clear();
    found_filtered.clear();
    found.shrink_to_fit();
    found_filtered.shrink_to_fit();
    return img;
}
