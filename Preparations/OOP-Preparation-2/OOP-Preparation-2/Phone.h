#ifndef __PHONE_H
#define __PHONE_H

class Phone {
	char* name = nullptr;
	int screensize;
	int number;

public:
	Phone(const char* name = "", const int screensize = 1, const int number = 0);
	~Phone();
	Phone(const Phone& toCopy);
	Phone& operator=(const Phone& toCopy);

	// Getters
	const char* getName() const;
	const int getSize() const;
	const int getNumber() const;

	// Setters
	void setName(const char* newName);
	void setScreensize(const int size);
	void setNumber(const int phoneNumber);

	// Other methods
	void call(const Phone& toCall) const;
	void print() const;
};

#endif