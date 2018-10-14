
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

