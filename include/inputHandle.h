#ifndef INCLUDE_INPUTHANDLE_H_
#define INCLUDE_INPUTHANDLE_H_

class inputHandle{
private:
	Mat image; /* the input image */
	string errorMessage;
public: 
	bool isReadSuccessful; // unit test
	Mat readImage(string imgName); // unit test
};

#endif    // INCLUDE_INPUTHANDLE_H_
