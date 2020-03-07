/* Kiril Vasilev Golov, 62360 */

#include <iostream>
#include "PC.h"

void testMonitor() {
	// Test constructors
	Monitor mon1;
	Monitor mon2("5852165", 1920, 1080);

	// Test operator <<
	std::cout << mon1 << mon2 << std::endl;

	// Test copy constructor and operator=
	Monitor mon3(mon2);
	mon1 = mon3;
	// Test setters
	mon2.setSerial("00223");
	mon2.setWidth(-5);
	mon2.setHeight(0);
	
	std::cout << mon1 << mon2 << mon3 << std::endl;

	// Test operator <
	mon3.setWidth(720);
	std::cout << "mon3 < mon1: " << (mon3 < mon1) << ", expected 1" << std::endl;
	std::cout << "mon2 < mon1: " << (mon2 < mon1) << ", expected 1" << std::endl;
	Monitor mon4(mon3);
	std::cout << "mon4 < mon3: " << (mon4 < mon3) << ", expected 0" << std::endl;
}

void testPC() {
	// Create new PC with one monitor and print it
	std::cout << "*Creating new PC: " << std::endl;
	PC computer(Monitor("12345", 1920, 1080), "9883");
	std::cout << computer;

	// Create new monitor and add it
	Monitor toBeAdded("56789", 1000, 800);
	std::cout << "*Adding new monitor." << std::endl;
	computer.add(toBeAdded);

	// Check if the new monitor was added
	std::cout << toBeAdded;
	if (computer.findBySerial(toBeAdded.getSerial())) {
		std::cout << "was added successfully." << std::endl;
	}
	else {
		std::cout << "was NOT added successfully." << std::endl;
	}

	// Print all the monitors connected to the PC
	std::cout << std::endl << "*Printing all info about the PC:" << std::endl;
	std::cout << computer;

	// ADDITIONAL TESTS
	std::cout << "*Additional tests: (testing operator[])" << std::endl;
	std::cout << computer[1];
}

int main() {
	// Original tests for Monitor class
	// testMonitor();
	
	// Required tests for PC class as per the task
	testPC();

	return 0;
}