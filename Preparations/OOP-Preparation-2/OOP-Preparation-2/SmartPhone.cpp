#include "SmartPhone.h"
#include <iostream>

SmartPhone::SmartPhone() : SmartDevice(), Phone(), cameraResolution(0) {

}

const int SmartPhone::getResolution() const {
	return cameraResolution;
}

void SmartPhone::setResolution(const int resolution) {
	cameraResolution = resolution;
}

void SmartPhone::print() const {
	SmartDevice::print();
	Phone::print();
	std::cout << "Camera resolution: " << getResolution() << std::endl;
}