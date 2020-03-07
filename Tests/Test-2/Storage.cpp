#include "Storage.h"
#include <cstring>

Storage::Storage(const char* hashCode, const char* name, const double maxCapacity, const double usedCapacity) {
	setHash(hashCode);
	setName(name);
	setMaxCap(maxCapacity);
	setUsedCap(usedCapacity);
}

Storage::~Storage() {
	delete[] hashCode;
	delete[] name;
}

Storage::Storage(const Storage& toCopy) : maxCapacity(toCopy.getMaxCap()), usedCapacity(toCopy.getUsedCap()) {
	setHash(toCopy.getHash());
	setName(toCopy.getName());
}

Storage& Storage::operator=(const Storage& toCopy) {
	if (this != &toCopy) {
		setHash(toCopy.getHash());
		setName(toCopy.getName());
		setMaxCap(toCopy.getMaxCap());
		setUsedCap(toCopy.getUsedCap());
	}
	return *this;
}

const char* Storage::getHash() const {
	return hashCode;
}

const char* Storage::getName() const {
	return name;
}

const double Storage::getMaxCap() const {
	return maxCapacity;
}

const double Storage::getUsedCap() const {
	return usedCapacity;
}

void Storage::setHash(const char* newHash) {
	if (newHash == nullptr) {
		return;
	}

	delete[] hashCode;
	hashCode = new char[strlen(newHash) + 1];
	strcpy_s(hashCode, strlen(newHash) + 1, newHash);
}

void Storage::setName(const char* newName) {
	if (newName == nullptr) {
		return;
	}

	delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

void Storage::setMaxCap(const double newMaxCap) {
	// Fail if we try to set the maximum capacity to less than the current used capacity
	if (newMaxCap < 0 || newMaxCap < getUsedCap()) {
		return;
	}

	maxCapacity = newMaxCap;
}

void Storage::setUsedCap(const double newUsedCap) {
	// Fail if we try to set the used capacity to more than the maximum capacity
	if (newUsedCap < 0 || newUsedCap > getMaxCap()) {
		return;
	}

	usedCapacity = newUsedCap;
}