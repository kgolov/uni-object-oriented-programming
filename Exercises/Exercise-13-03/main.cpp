#include <iostream>
#include "user.h"

void testUser() {
	User u1;
	User u2("Test", { 1, 5, 1990 }, 'M');
	User u3('S');
	User u4('F');

	std::cout << u1.isDefined() << std::endl;
	std::cout << u2.isDefined() << std::endl;

	u1.setGender('H');
	u1.setGender('M');
	u1.setDate({ 11, 4, 1999 });
	u1.setName("Hello");

	std::cout << u1.isDefined() << std::endl << std::endl;

	u3 = u2;
	u3.setName("NewName");
	std::cout << u2.getName() << std::endl;
	std::cout << u3.getName() << std::endl;
}

int main() {
	testUser();
	return 0;
}