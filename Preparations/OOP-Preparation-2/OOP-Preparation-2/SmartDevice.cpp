#include "SmartDevice.h"
#include <iostream>

SmartDevice::SmartDevice(const int RAM, const int speed, const int cores) :
	productNumber(current + 1), RAM(RAM), speed(speed), cores(cores) {
	current++;
}

const int SmartDevice::getProductNumber() const {
	return productNumber;
}

const int SmartDevice::getRAM() const {
	return RAM;
}

const int SmartDevice::getCores() const {
	return cores;
}

const int SmartDevice::getSpeed() const {
	return speed;
}

void SmartDevice::setProductNumber(const int productNumber) {
	this->productNumber = productNumber;
}

void SmartDevice::setRAM(const int RAM) {
	this->RAM = RAM;
}

void SmartDevice::setCores(const int cores) {
	this->cores = cores;
}

void SmartDevice::setSpeed(const int speed) {
	this->speed = speed;
}

void SmartDevice::print() const {
	std::cout << "Product N: " << getProductNumber() << std::endl;
	std::cout << "RAM: " << getRAM() << std::endl;
	std::cout << "Speed: " << getSpeed() << std::endl;
	std::cout << "Cores: " << getCores() << std::endl;
}