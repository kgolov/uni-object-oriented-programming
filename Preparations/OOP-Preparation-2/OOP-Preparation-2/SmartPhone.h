#ifndef __SMART_PHONE_H
#define __SMART_PHONE_H

#include "SmartDevice.h"
#include "Phone.h"

class SmartPhone : public SmartDevice, public Phone {
	int cameraResolution;

public:
	SmartPhone();

	// Getters
	const int getResolution() const;
	
	// Setters
	void setResolution(const int resolution);

	// Other methods
	void print() const;
};

#endif