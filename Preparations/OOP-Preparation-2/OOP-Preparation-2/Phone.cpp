#include "Phone.h"
#include <iostream>
#include <cstring>

Phone::Phone(const char* name, const int screensize, const int number) :
	screensize(screensize), number(number) {
	setName(name);
}

Phone::~Phone() {
	delete[] name;
}

Phone::Phone(const Phone& toCopy) {
	setName(toCopy.getName());
	setScreensize(toCopy.getSize());
	setNumber(toCopy.getNumber());
}

Phone& Phone::operator=(const Phone& toCopy) {
	if (this != &toCopy) {
		setName(toCopy.getName());
		setScreensize(toCopy.getSize());
		setNumber(toCopy.getNumber());
	}
	return *this;
}

const char* Phone::getName() const {
	return name;
}

const int Phone::getSize() const {
	return screensize;
}

const int Phone::getNumber() const {
	return number;
}

void Phone::setName(const char* newName) {
	if (newName == nullptr) {
		return;
	}

	delete[] name;

	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

void Phone::setScreensize(const int size) {
	screensize = size;
}

void Phone::setNumber(const int phoneNumber) {
	number = phoneNumber;
}

void Phone::call(const Phone& toCall) const {
	std::cout << "Calling phone number: " << toCall.getNumber() << std::endl;
}

void Phone::print() const {
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Screensize: " << getSize() << std::endl;
	std::cout << "Phone number: " << getNumber() << std::endl;
}