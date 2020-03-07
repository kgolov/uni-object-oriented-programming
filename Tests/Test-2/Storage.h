#ifndef __STORAGE_H
#define __STORAGE_H

#include <iostream>

class Storage {
	char* hashCode = nullptr;
	char* name = nullptr;
	double maxCapacity = 0;
	double usedCapacity = 0;

public:
	Storage(const char* hashCode = "", const char* name = "", const double maxCapacity = 0,
		const double usedCapacity = 0);
	~Storage();
	Storage(const Storage& toCopy);
	Storage& operator=(const Storage& toCopy);	

	// Getters
	const char* getHash() const;
	const char* getName() const;
	const double getMaxCap() const;
	const double getUsedCap() const;

	// Setters
	void setHash(const char* newHash);
	void setName(const char* newName);
	void setMaxCap(const double newMaxCap);
	void setUsedCap(const double newUsedCap);
};

#endif