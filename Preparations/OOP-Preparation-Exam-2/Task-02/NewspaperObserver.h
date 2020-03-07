#pragma once

#include "Observer.h"

class NewspaperObserver : public Observer {
	string name;
	string city;
	double temperature;

public:
	NewspaperObserver(const string& name = "", const string& city = "", const double temp = 0);
	NewspaperObserver(const NewspaperObserver& toCopy);

	void update(const string& city, const double temp) override;
	const string& getName() const override;

	void printMeteo() const;
};