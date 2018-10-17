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



#include <iostream>
#include <vector>
#include "perception.h"
#include "inputHandle.h"
#include "imageProcess.h"
#include "hogHumanDetect.h"
#include "outputDisplay.h"
#include <fstream>
#include <sstream>
#include <dirent.h>
#include <opencv2/core/ocl.hpp> 

int main() {

	cv::ocl::setUseOpenCL(false);

	perception* perceptionObject = new perception();

	perceptionObject->outputDisplayObject.writefile.open ("../perception.txt");
	DIR *pDIR;
	std::vector<std::string> files;
	struct dirent *entry;
	if( (pDIR = opendir("../imageData/Data")) ){
		while((entry = readdir(pDIR))){
			if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
				std::string imageName = entry->d_name;
				perceptionObject->run(imageName);
			}
		}
		closedir(pDIR);
		delete entry;
	}
	else{
		std::cout << "CANNOT OPEN!!!" << std::endl;
	}
	perceptionObject->outputDisplayObject.writefile.close();

	delete perceptionObject;
	return 0;
}