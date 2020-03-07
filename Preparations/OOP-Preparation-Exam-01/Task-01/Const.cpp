#include "Const.h"
#include <iostream>

Const::Const(const double newVal = 0) : Expression(newVal) {

}

const double Const::value() const {
	return val;
}

void Const::print() const {
	std::cout << val;
}