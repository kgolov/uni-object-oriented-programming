#include "Guest.h"
#include <cstring>

Guest::Guest() {
	setIP("");
}

Guest::~Guest() {
	delete[] ipaddr;
}

Guest::Guest(const Guest& toCopy) {
	setIP(toCopy.getIP());
}

Guest& Guest::operator=(const Guest& toCopy) {
	if (this != &toCopy) {
		setIP(toCopy.getIP());
	}
	return *this;
}

Guest::Guest(const char* address) {
	setIP(address);
}

void Guest::setIP(const char* address) {
	if (address == nullptr) {
		return;
	}

	delete[] ipaddr;

	ipaddr = new char[strlen(address) + 1];
	strcpy_s(ipaddr, strlen(address) + 1, address);
}