#include "CentralBank.h"

CentralBank::CentralBank(const string& name) : name(name) {

}

const int CentralBank::findCurrency(const string& currency) const {
	int index = -1;

	for (int i = 0; i < rates.size(); i++) {
		if (rates[i].currency == currency) {
			index = i;
		}
	}

	return index;
}

void CentralBank::addCurrency(const Entry& entry) {
	int existsAtIndex = findCurrency(entry.currency);
	if (existsAtIndex != -1) {
		// There is already such currency
		return;
	}
	
	// Else, there is not such currency
	// Add it to the list
	rates.push_back(entry);
}

void CentralBank::deleteCurrency(const string& currency) {
	int index = findCurrency(currency);

	if (index != -1) {
		rates.erase(rates.begin() + index);
	}
}

void CentralBank::setRate(const string& currency, const double rate) {
	int index = findCurrency(currency);

	if (index != -1) {
		rates[index].rate = rate;
	}
}

void CentralBank::regist(Observer* observer) {
	observers.push_back(observer);
}

void CentralBank::unregister(const int index) {
	if (index < 0 || index >= observers.size()) {
		return;
	}

	observers.erase(observers.begin() + index);
}

void CentralBank::notify(const string& currency) {
	int index = findCurrency(currency);
	if (index == -1) {
		return;
	}
	double rate = rates[index].rate;

	for (int i = 0; i < observers.size(); i++) {
		observers[i]->update(currency, rate);
	}
}