#include "PC.h"

PC::PC() {
	maxSize = 1;
	monitors = new Monitor[maxSize];
	current = 0;
	
	serialN = new char[1];
	serialN[0] = '\0';
}

PC::~PC() {
	delete[] monitors;
	delete[] serialN;
}

PC::PC(const char* serial) {
	maxSize = 1;
	monitors = new Monitor[maxSize];
	current = 0;

	setSerial(serial);
}

PC::PC(const Monitor& toAdd) {
	maxSize = 1;
	monitors = new Monitor[maxSize];
	current = 0;

	add(toAdd);
	setSerial("");
}

PC::PC(const Monitor& toAdd, const char* serial) {
	maxSize = 1;
	monitors = new Monitor[maxSize];
	current = 0;

	add(toAdd);
	setSerial(serial);
}

PC::PC(const PC& toCopy) : maxSize(toCopy.maxSize), current(toCopy.current) {
	monitors = new Monitor[maxSize];

	for (int i = 0; i < current; i++) {
		monitors[i] = toCopy.monitors[i];
	}

	setSerial(toCopy.getSerial());
}

PC& PC::operator=(const PC& toCopy) {
	if (this != &toCopy) {
		delete[] monitors;

		maxSize = toCopy.maxSize;
		current = toCopy.current;
		monitors = new Monitor[maxSize];

		for (int i = 0; i < current; i++) {
			monitors[i] = toCopy.monitors[i];
		}

		// No need to delete[] serialN because the setter does it
		setSerial(toCopy.getSerial());
	}
	return *this;
}

bool PC::isFull() const {
	return current >= maxSize;
}

bool PC::isEmpty() const {
	return current <= 0;
}

void PC::resize() {
	maxSize *= 2;

	Monitor* newMonitors = new Monitor[maxSize];

	for (int i = 0; i < current; i++) {
		newMonitors[i] = monitors[i];
	}

	delete[] monitors;
	monitors = newMonitors;
}

Monitor PC::getAt(int index) const {
	if (index < 0 || index >= current) {
		return Monitor();
	}

	return monitors[index];
}

Monitor PC::operator[](int index) const {
	return getAt(index);
}

const int PC::connectedMonitors() const {
	return current;
}

const char* PC::getSerial() const {
	return serialN;
}

void PC::add(const Monitor& toAdd) {
	if (isFull()) {
		resize();
	}

	monitors[current] = toAdd;
	current++;
}

void PC::operator+=(const Monitor& toAdd) {
	add(toAdd);
}

void PC::setSerial(const char* serial) {
	delete[] serialN;

	if (serial == nullptr) {
		serialN = new char[1];
		serialN[0] = '\0';
	}
	else {
		int size = strlen(serial) + 1;
		serialN = new char[size];
		strcpy_s(serialN, size, serial);
	}
}

bool PC::findBySerial(const char* serial) const {
	if (serial == nullptr) {
		return false;
	}

	for (int i = 0; i < current; i++) {
		if (strcmp(monitors[i].getSerial(), serial) == 0) {
			return true;
		}
	}

	return false;
}

std::ostream& operator<<(std::ostream& os, const PC& obj) {
	os << "PC with serial N " << obj.getSerial() << std::endl;
	os << obj.connectedMonitors() << " connected monitors: " << std::endl;
	
	for (int i = 0; i < obj.connectedMonitors(); i++) {
		os << obj.monitors[i];
	}

	os << std::endl;

	return os;
}