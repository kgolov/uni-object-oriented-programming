#include "NewspaperObserver.h"
#include <iostream>

NewspaperObserver::NewspaperObserver(const string& name, const string& city, const double temp) :
	name(name), city(city), temperature(temp){

}

NewspaperObserver::NewspaperObserver(const NewspaperObserver& toCopy) :
	name(toCopy.name), city(toCopy.city), temperature(toCopy.temperature) {

}

void NewspaperObserver::update(const string& city, const double temp) {
	this->city = city;
	temperature = temp;

	std::cout << "Update " << name << ": The temperature in " << this->city << " is " << temperature << std::endl;
}

const string& NewspaperObserver::getName() const {
	return name;
}

void NewspaperObserver::printMeteo() const {
	std::cout << "Newspaper " << name << ": The temperature in " << city << " is " << temperature << std::endl;
}