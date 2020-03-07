#include "Var.h"
#include <cstring>
#include <iostream>

Var::Var(const double newVal = 0, const char* newName = "") : Expression(newVal) {
	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

Var::~Var() {
	delete[] name;
}

Var::Var(const Var& toCopy) : Expression(toCopy.val) {
	name = new char[strlen(toCopy.name) + 1];
	strcpy_s(name, strlen(toCopy.name) + 1, toCopy.name);
}

Var& Var::operator=(const Var& toCopy) {
	delete[] name;
	name = new char[strlen(toCopy.name) + 1];
	strcpy_s(name, strlen(toCopy.name) + 1, toCopy.name);

	val = toCopy.val;
}

const double Var::value() const {
	return val;
}

void Var::print() const {
	std::cout << name;
}

void Var::setValue(const double newVal) {
	val = newVal;
}