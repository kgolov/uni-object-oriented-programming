#ifndef __MONITOR_H
#define __MONITOR_H

#include <iostream>
#include <cstring>

class Monitor {
private:
	char* serialN = nullptr;
	int width;
	int height;

public:
	Monitor();
	~Monitor();
	Monitor(const char* serial, int _width, int _height);
	Monitor(const Monitor& toCopy);
	Monitor& operator=(const Monitor& toCopy);

	// Getters
	const char* getSerial() const;
	const int getWidth() const;
	const int getHeight() const;

	// Setters
	void setSerial(const char* serial);
	void setWidth(int _width);
	void setHeight(int _height);

	// Other methods and operators
	bool operator<(const Monitor& rhs) const;
	friend std::ostream& operator<<(std::ostream& os, const Monitor& obj);
};

#endif