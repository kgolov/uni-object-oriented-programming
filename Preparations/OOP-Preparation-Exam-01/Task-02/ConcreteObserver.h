#pragma once

#include "Observer.h"

class ConcreteObserver : public Observer {
	string name;

public:
	ConcreteObserver(const string& name = "");

	void update(const string& currency, const double rate) const override;
};