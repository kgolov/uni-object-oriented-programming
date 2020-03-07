#include "Monitor.h"

Monitor::Monitor() {
	serialN = new char[1];
	serialN[0] = '\0';
	width = 0;
	height = 0;
}

Monitor::~Monitor() {
	delete[] serialN;
}

Monitor::Monitor(const Monitor& toCopy) : width(toCopy.getWidth()), height(toCopy.getHeight()) {
	setSerial(toCopy.getSerial());
}

Monitor::Monitor(const char* serial, int _width, int _height) {
	setSerial(serial);
	setWidth(_width);
	setHeight(_height);
}

Monitor& Monitor::operator=(const Monitor& toCopy) {
	if (this != &toCopy) {
		setSerial(toCopy.getSerial());
		setWidth(toCopy.getWidth());
		setHeight(toCopy.getHeight());
	}
	return *this;
}

const char* Monitor::getSerial() const {
	return serialN;
}

const int Monitor::getWidth() const {
	return width;
}

const int Monitor::getHeight() const {
	return height;
}

void Monitor::setSerial(const char* serial) {
	if (serial == nullptr) {
		return;
	}

	delete[] serialN;

	int size = strlen(serial) + 1;
	serialN = new char[size];
	strcpy_s(serialN, size, serial);
} 

void Monitor::setWidth(int _width) {
	if (_width < 0) {
		return;
	}

	width = _width;
}

void Monitor::setHeight(int _height) {
	if (_height < 0) {
		return;
	}

	height = _height;
}

bool Monitor::operator<(const Monitor& rhs) const {
	if (this->getWidth() != rhs.getWidth()) {
		return this->getWidth() < rhs.getWidth();
	}
	else {
		return this->getHeight() < rhs.getHeight();
	}
}

std::ostream& operator<<(std::ostream& os, const Monitor& obj) {
	os << "Monitor N: " << obj.getSerial() << ", width " << obj.getWidth() << "px, height "
		<< obj.getHeight() << "px." << std::endl;

	return os;
}