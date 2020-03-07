#include "ConcreteObserver.h"
#include <iostream>

ConcreteObserver::ConcreteObserver(const string& name) : name(name) {

}

void ConcreteObserver::update(const string& currency, const double rate) const {
	std::cout << "Update " << name << ": " << currency << " " << rate << std::endl;
}