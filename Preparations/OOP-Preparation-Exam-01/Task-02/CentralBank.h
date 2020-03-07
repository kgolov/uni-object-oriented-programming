#pragma once

#include <string>
#include <vector>
#include "Observer.h"

using std::string;
using std::vector;

struct Entry {
	string currency;
	double rate;
};

class CentralBank {
	string name;
	vector<Entry> rates;
	vector<Observer*> observers;

protected:
	const int findCurrency(const string& currency) const;

public:
	CentralBank(const string& name = "");

	void addCurrency(const Entry& entry);
	void deleteCurrency(const string& currency);
	void setRate(const string& currency, const double rate);

	void regist(Observer* observer);
	void unregister(const int index);
	void notify(const string& currency);
};