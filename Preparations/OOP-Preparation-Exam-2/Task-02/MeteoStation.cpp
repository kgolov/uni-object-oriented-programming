#include "MeteoStation.h"
#include <iostream>

MeteoStation::MeteoStation(const string& city, const double temp) : city(city), temperature(temp) {

}

const string& MeteoStation::getCity() const {
	return city;
}

const double MeteoStation::getTemperature() const {
	return temperature;
}

void MeteoStation::setTemperature(const double newTemp) {
	temperature = newTemp;
	
	notify();
}

const int MeteoStation::findObserver(const string& name) {
	int index = -1;

	for (int i = 0; i < observers.size(); i++) {
		if (observers[i]->getName() == name) {
			index = i;
		}
	}
	
	return index;
}

void MeteoStation::Register(Observer* observer) {
	/* // Checking type of observer
	const Observer* tmp;

	if (tmp = dynamic_cast<const NewspaperObserver*>(observer)) {
		// The observer is a NewspaperObserver
		// Add them to the list
		NewspaperObserver* toAdd = new NewspaperObserver(dynamic_cast<const NewspaperObserver&>(*tmp));
		observers.push_back(toAdd);
	}
	else {
		// The observer is not a known type
		std::cout << "*Error: Unknown observer type!" << std::endl;
	} */
	observers.push_back(observer);
}

void MeteoStation::unregister(const int index) {
	if (index < 0 || index >= observers.size()) {
		return;
	}

	observers.erase(observers.begin() + index);
}

void MeteoStation::unregister(const string& name) {
	unregister(findObserver(name));
}

void MeteoStation::notify() const {
	for (int i = 0; i < observers.size(); i++) {
		observers[i]->update(city, temperature);
	}
}