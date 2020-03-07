#ifndef __GUEST_H
#define __GUEST_H

class Guest {
protected:
	char* ipaddr = nullptr;

public:
	Guest();
	~Guest();
	Guest(const Guest& toCopy);
	Guest& operator=(const Guest& toCopy);
	Guest(const char* address);

	// Setters
	void setIP(const char* address);

	// Getters
	const char* getIP() const { return ipaddr; }
};

#endif