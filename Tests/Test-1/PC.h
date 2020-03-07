#ifndef __PC_H
#define __PC_H

#include "Monitor.h"

class PC {
private:
	Monitor* monitors = nullptr;
	int maxSize;
	int current;
	char* serialN = nullptr;

	bool isFull() const;
	void resize();

public:
	PC();
	~PC();
	PC(const char* serial);
	PC(const Monitor& toAdd);
	PC(const Monitor& toAdd, const char* serial);
	PC(const PC& toCopy);
	PC& operator=(const PC& toCopy);

	// Getters
	bool isEmpty() const;
	Monitor getAt(int index) const;
	Monitor operator[](int index) const;
	const int connectedMonitors() const;
	const char* getSerial() const;

	// Setters
	void add(const Monitor& toAdd);
	void operator+=(const Monitor& toAdd);
	void setSerial(const char* serial);

	// Other methods
	bool findBySerial(const char* serial) const;

	// For debugging
	friend std::ostream& operator<<(std::ostream& os, const PC& obj);
};

#endif