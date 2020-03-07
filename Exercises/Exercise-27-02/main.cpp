#include <iostream>
#include "vector.h"

void testVector() {
	Vector v1, v2(3);

	v1.addElement(1);

	std::cout << v1.getElement(0) << std::endl;
	std::cout << v1.getElement(5) << std::endl;
	std::cout << v2.getElement(1) << std::endl;

	v2.addElement(-5);
	v2.addElement(-4);
	v2.addElementAtIndex(-3, 1);

	v2.print();

	v1.addElement(100);

	v1.print();
}

int main() {
	testVector();

	int x;
	std::cin >> x;
	
	return 0;
}