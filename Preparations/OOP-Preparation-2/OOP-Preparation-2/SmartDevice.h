#ifndef __SMART_DEVICE_H
#define __SMART_DEVICE_H

static int current = 0;

class SmartDevice {
private:
	int productNumber;
	int RAM;
	int speed;
	int cores;
	
	// Setters
	void setProductNumber(const int productNumber);

public:
	SmartDevice(const int RAM = 1, const int speed = 1, const int cores = 1);

	// Getters
	const int getProductNumber() const;
	const int getRAM() const;
	const int getSpeed() const;
	const int getCores() const;

	// Setters
	void setRAM(const int RAM);
	void setSpeed(const int speed);
	void setCores(const int cores);

	// Other methods
	void print() const;
};

#endif