#ifndef INCLUDE_HOGHUMANDETECT_H_
#define INCLUDE_HOGHUMANDETECT_H_

class hogHumanDetect{
private:

public:
	HOGDescriptor hog;
	void setHogSVM(HOGDescriptor& hog);
};

#endif    // INCLUDE_HOGHUMANDETECT_H_
