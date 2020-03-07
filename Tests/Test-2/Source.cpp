/* Kiril Vasilev Golov, 62360
   Compiler: Visual Studio 2017 
   Compiles without errors */

#include <iostream>
#include "OnlineStorage.h"

// Original tests for Storage class
void testStorage() {
	// USE DEBUGGER TO SEE BEHAVIOUR

	// Test constructors
	Storage s1, s2("hssfdslfg", "TestName", 10.0, 11.0);
	// Test copy constructor and operator=, setters
	s2.setUsedCap(9.0);
	Storage s3(s2);
	s1 = s3;
}

// Original tests for OnlineService class
void testOnlineService() {
	// USE DEBUGGER TO SEE BEHAVIOUR
	
	OnlineService s1(0, 0, 3), s2(80, 4, 5);
	std::cout << s1.isConnected() << std::endl;
	std::cout << s2.isConnected() << std::endl;
	std::cout << s2.connectDevice() << std::endl;
	std::cout << s2.connectDevice() << std::endl;
	s2.disconnectDevice();
	std::cout << s2.connectDevice() << std::endl;
	std::cout << s1.connectDevice() << std::endl;
	std::cout << s1.isConnected() << std::endl;
	std::cout << "Expected: 0 1 1 0 1 1 1" << std::endl;
}

// Original tests for OnlineStorage class
void testOnlineStorage() {
	// USE DEBUGGER TO SEE BEHAVIOUR
	OnlineStorage s1("3u487yyd12gad21efadf", "OOP-Exams-Dont-Steal", 8, 7.5, 80, 3, 5, 3.5);

	std::cout << "Uploading 1300MB of files!" << std::endl;
	s1.uploadFiles(1300);

	OnlineStorage s2("3u487yyd12gad21efadx", "OOP-Exams-Dont-Steal2", 8, 5.5, 80, 0, 5, 3.5);

	std::cout << std::endl << "Uploading 1300MB of files!" << std::endl;
	s2.uploadFiles(1300);
}


int main() {
	// Original tests
	// testStorage();
	// testOnlineService();
	// testOnlineStorage();

	// Task as required
	OnlineStorage s1("3u487yyd12gad21efadf", "OOP-Exams-Dont-Steal", 8, 5.5, 80, 3, 5, 3.5);

	std::cout << "Uploading 1300MB of files!" << std::endl;
	s1.uploadFiles(1300);

	std::cout << std::endl << "Price per month for " << s1.getUsedCap() << "GB: " << s1.calculatePerMonth() <<
		std::endl;

	return 0;
}