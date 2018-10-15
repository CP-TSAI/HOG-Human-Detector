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

int main() {
	perception perceptionObject;
	perceptionObject.outputDisplayObject.writefile.open ("../perception.txt");
	DIR *pDIR;
	std::vector<std::string> files;
	struct dirent *entry;
	if( (pDIR = opendir("../imageData/Data")) ){
		while((entry = readdir(pDIR))){
			if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
				std::string imageName = entry->d_name;
				//folderName = "../imageData/Data/";
				perceptionObject.run(imageName);
			}
		}
		closedir(pDIR);
	}
	else{
		std::cout << "CANNOT OPEN!!!" << std::endl;
	}
	perceptionObject.outputDisplayObject.writefile.close();
	return 0;
}