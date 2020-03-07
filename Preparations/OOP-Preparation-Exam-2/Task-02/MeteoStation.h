#pragma once

#include "NewspaperObserver.h"

#include <string>
#include <vector>
using std::string;
using std::vector;

class MeteoStation {
	string city;
	double temperature;
	vector<Observer*> observers;

	const int findObserver(const string& name);

public:
	MeteoStation(const string& city = "", const double temp = 0);

	const string& getCity() const;
	const double getTemperature() const;

	void setTemperature(const double newTemp);

	void Register(Observer* observer);
	void unregister(const int index);
	void unregister(const string& name);
	void notify() const;
};