/** @file main.cpp
 *  @brief This file create perception object and run algorithm
 *  @copyright (c) 2018 Chien-Te Lee, Chin-Po Tsai
 *  @author Chien-Te Lee, Chin-Po Tsai
 *  @date   10/16/2018
 *
 *		This file reads sample image, creates a perceptionObject to run
 *      hog human detect algorithm
 *  	
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "perception.h"
#include "inputHandle.h"
#include "imageProcess.h"
#include "hogHumanDetect.h"
#include "outputDisplay.h"
#include <dirent.h>
// #include <opencv2/core/ocl.hpp>

/**
 *  @brief the pipe of the process
*/
int main() {
    // cv::ocl::setUseOpenCL(false);

    ///< create perception object
    perception* perceptionObject = new perception();

    perceptionObject->outputDisplayObject.writefile.open("../perception.txt");

    DIR *pDIR;
    std::vector<std::string> files;
    struct dirent *entry;
    ///< read image from dataset
    if ((pDIR = opendir("../imageData/Data"))) {
        while ((entry = readdir(pDIR))) {
            if ( strcmp(entry->d_name, ".") != 0 \
                && strcmp(entry->d_name, "..") != 0 ) {
                std::string imageName = entry->d_name;
                ///< run hog human detect algorithm
                perceptionObject->run(imageName);
            }
        }
        closedir(pDIR);
        delete entry;
    } else {
        std::cout << "CANNOT OPEN!!!" << std::endl;
    }
    perceptionObject->outputDisplayObject.writefile.close();

    delete perceptionObject;
    return 0;
}
