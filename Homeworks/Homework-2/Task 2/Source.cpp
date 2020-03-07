#include <iostream>
#include "Game.h"

int main() {
	Warrior w1;
	
	w1.print();

	Warrior w2(w1);

	w2.print();

	Wizzard wz1;

	wz1.print();

	w2.getattacked(wz1);

	w2.print();

	return 0;
}