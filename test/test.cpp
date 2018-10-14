
#include <gtest/gtest.h>
#include <string>
#include "perception.h"
#include "inputHandle.h"
#include "imageProcess.h"
#include "hogHumanDetect.h"
#include "outputDisplay.h"


// test perception member
TEST(perceptionTest, testPerceptiomMember){
	perception perceptionObject;

	// test inputHandleObject
	std::string name =  typeid(perceptionObject.inputHandleObject).name();
	std::string test = "inputHandle";
	std::size_t pos = name.find(test);  
	std::string substr = name.substr(pos, test.size());
	EXPECT_EQ(test, substr);


	// test imageProcessObject
	name =  typeid(perceptionObject.imageProcessObject).name();
	test = "imageProcess";
	pos = name.find(test);  
	substr = name.substr(pos, test.size());
	EXPECT_EQ(test, substr);

	// test hogHumanDetectObject
	name =  typeid(perceptionObject.hogHumanDetectObject).name();
	test = "hogHumanDetect";
	pos = name.find(test);  
	substr = name.substr(pos, test.size());
	EXPECT_EQ(test, substr);

	// test outputDisplayObject
	name =  typeid(perceptionObject.outputDisplayObject).name();
	test = "outputDisplay";
	pos = name.find(test);  
	substr = name.substr(pos, test.size());
	EXPECT_EQ(test, substr);
}


// inputHandle
TEST(inputHandleTest, testInputHandleReadImage){
	perception perceptionObject1;
	perceptionObject1.image = perceptionObject1.inputHandleObject.readImage("../imageData/Testcase/person_062.bmp");
	EXPECT_EQ(int(perceptionObject1.inputHandleObject.isReadSuccessful), 1);

	// give a non-existent image
	perception perceptionObject2;
	perceptionObject2.image = perceptionObject2.inputHandleObject.readImage("../imageData/Testcase/person_06d2.bmp");
	EXPECT_NE(int(perceptionObject2.inputHandleObject.isReadSuccessful), 1);
}


// imageProcess
TEST(imageProcessTest, testImageProcessResizeImage){
	perception perceptionObject;
	perceptionObject.image = perceptionObject.inputHandleObject.readImage("../imageData/Testcase/person_082.bmp");
	cv::Mat imageResized = perceptionObject.imageProcessObject.resizeImage(perceptionObject.image);
	EXPECT_EQ(imageResized.rows, 480);
	EXPECT_EQ(imageResized.cols, 640);
}

TEST(imageProcessTest, testImageProcessToGray){
	perception perceptionObject;

	// give a color image
	perceptionObject.image = perceptionObject.inputHandleObject.readImage("../imageData/Testcase/person_082.bmp");
	EXPECT_EQ(perceptionObject.image.channels(), 3);

	cv::Mat imageGray = perceptionObject.imageProcessObject.toGray(perceptionObject.image);
	EXPECT_EQ(imageGray.channels(), 1);
}


TEST(imageProcessTest, testImageProcessLowPassFilter){
	perception perceptionObject;
	perceptionObject.image = perceptionObject.inputHandleObject.readImage("../imageData/Testcase/person_062.bmp");
	
	cv::Mat imageLowPass1 = perceptionObject.imageProcessObject.lowPassFilter(perceptionObject.image);

	cv::Mat imageLowPass2 = perceptionObject.image;
	blur(imageLowPass2, imageLowPass2, cv::Size(3, 3));


	// Get a matrix with non-zero values at points where the 
	// two matrices have different values
	// Equal if no elements disagree
	cv::Mat diff = imageLowPass1 != imageLowPass2;

	// access the element of diff matrix, if it's all zero,
	// then it means the images are the same
	int counter = 0;
	for(size_t nrow = 0; nrow < (size_t) diff.rows; nrow++) {  
	   for(size_t ncol = 0; ncol < (size_t) diff.cols; ncol++) {  
	       cv::Vec3b bgr = diff.at<cv::Vec3b>(nrow,ncol);
	       counter = counter + (bgr.val[0] + bgr.val[1] + bgr.val[2]);
	   }  
	} 
	EXPECT_EQ(counter, 0);
}


