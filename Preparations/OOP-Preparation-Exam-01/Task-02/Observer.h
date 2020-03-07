#pragma once

#include <string>
using std::string;

class Observer {
public:
	virtual void update(const string& currency, const double rate) const = 0;
};