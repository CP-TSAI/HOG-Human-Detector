
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "perception.h"
#include "inputHandle.h"
#include "imageProcess.h"
#include "hogHumanDetect.h"
#include "outputDisplay.h"


// test inputHandle
TEST(inputHandleTest, testInputHandleReadImage){
	// give existent image
	perception perceptionObject1;
	perceptionObject1.image = perceptionObject1.inputHandleObject.readImage("../imageData/Testcase/person_062.bmp");
	EXPECT_EQ(int(perceptionObject1.inputHandleObject.isReadSuccessful), 1);

	// give a non-existent image
	perception perceptionObject2;
	perceptionObject2.image = perceptionObject2.inputHandleObject.readImage("../imageData/Testcase/person_06d2.bmp");
	EXPECT_NE(int(perceptionObject2.inputHandleObject.isReadSuccessful), 1);
}


// test imageProcess
TEST(imageProcessTest, testImageProcessResizeImage){
	perception perceptionObject;
	perceptionObject.image = perceptionObject.inputHandleObject.readImage("../imageData/Testcase/person_082.bmp");

	EXPECT_EQ(perceptionObject.image.rows, 640);
	EXPECT_EQ(perceptionObject.image.cols, 480);

	cv::Mat imageResized = perceptionObject.imageProcessObject.resizeImage(perceptionObject.image);
	EXPECT_EQ(imageResized.rows, 480);
	EXPECT_EQ(imageResized.cols, 640);
}


TEST(imageProcessTest, testImageProcessToGray){
	perception perceptionObject;

	// give a color image
	perceptionObject.image = perceptionObject.inputHandleObject.readImage("../imageData/Testcase/person_062.bmp");
	EXPECT_EQ(perceptionObject.image.channels(), 3);

	cv::Mat imageGray = perceptionObject.imageProcessObject.toGray(perceptionObject.image);
	EXPECT_EQ(imageGray.channels(), 1);
}


TEST(imageProcessTest, testImageProcessHistogramEqualization){
	perception perceptionObject;
	perceptionObject.image = perceptionObject.inputHandleObject.readImage("../imageData/Testcase/person_062.bmp");
	cv::Mat imageGray = perceptionObject.imageProcessObject.toGray(perceptionObject.image);
	cv::Mat imageHistogramEqualized = perceptionObject.imageProcessObject.histogramEqualization(imageGray);
	EXPECT_EQ(imageHistogramEqualized.channels(), 1);

	int num = cv::countNonZero(imageGray!=imageHistogramEqualized);
	EXPECT_NE(num, 0);
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



// test hogHumanDetect
TEST(hogHumanDetectTest, testHogHumanDetectMember){
	perception perceptionObject;
	perceptionObject.hogHumanDetectObject.setHogSVM(perceptionObject.hogHumanDetectObject.hog);

	EXPECT_EQ(perceptionObject.hogHumanDetectObject.hog, cv::Size(16,16));
}


// test outputDisplay
TEST(outputDisplayTest, testMarkHuman){
	perception perceptionObject;
	perceptionObject.image = perceptionObject.inputHandleObject.readImage("../imageData/Testcase/person_062.bmp");

	cv::HOGDescriptor hog;
	hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());


	std::vector<cv::Rect> found, found_filtered;
	hog.detectMultiScale(perceptionObject.image, found, 0, cv::Size(8, 8), cv::Size(32, 32), 1.05, 2);
	std::size_t i, j;
	for (i = 0; i < found.size(); i++) {
		cv::Rect r = found[i];
		for (j = 0; j < found.size(); j++)
			if (j != i && (r & found[j]) == r)
				break;
		if (j == found.size())
			found_filtered.push_back(r);
	}
	EXPECT_GT(int(found_filtered.size()), 0);
}


TEST(outputDisplayTest, testOutputImage){
	perception perceptionObject;
	perceptionObject.image = perceptionObject.inputHandleObject.readImage("../imageData/Testcase/person_062.bmp");
	cv::Mat outImg = perceptionObject.outputDisplayObject.outputImage(perceptionObject.image, "test2.png");
	EXPECT_NE(outImg.empty(), 1);
}

// test perception
TEST(perceptionTest2, testPerceptionRun){
	perception perceptionObject1;
	perceptionObject1.outputDisplayObject.writefile.open ("../test.txt");
	std::string imageName = "test.bmp";
	perceptionObject1.run(imageName);
	EXPECT_NE(perceptionObject1.imageResult.empty(), 0);
	perceptionObject1.outputDisplayObject.writefile.close();

}

