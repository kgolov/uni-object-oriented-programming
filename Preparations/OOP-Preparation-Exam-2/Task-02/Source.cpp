#include "MeteoStation.h"
#include <iostream>

int main() {
	MeteoStation station("Sofia", 25.0);
	NewspaperObserver ob1("Observer1", "Sofia");
	NewspaperObserver ob2("Observer2", "Sofia");

	station.Register(&ob1);
	station.Register(&ob2);

	station.setTemperature(30.0);

	ob1.printMeteo();
	ob2.printMeteo();

	station.unregister("Observer2");

	station.setTemperature(27.5);

	ob1.printMeteo();
	ob2.printMeteo();

	return 0;
}