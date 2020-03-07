#pragma once

#include <string>
using std::string;

class Observer {
public:
	virtual void update(const string& city, const double temp) = 0;
	virtual const string& getName() const = 0;
};