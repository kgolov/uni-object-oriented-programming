#include <iostream>
#include "MagicBox.h"

int main() {
	MagicBox<double> h;
	h.insert(1.111);
	h.insert(2.222);
	h.insert(3.333);
	h.insert(4.444);
	h.insert(5.555);
	h.insert(6.666);
	h.insert(7.777);

	h.list();

	std::cout << std::endl << h.pop() << std::endl << h.pop() << std::endl << std::endl;

	h.list();

	return 0;
}