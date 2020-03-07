// Kiril Vasilev Golov, f.n. 62360
// Compiled on Visual Studio 2019 version 16.1.1

#include <iostream>
#include "Environment.h"

int main() {
	// Create a player with Location(13, 13, 13), damage of 23 and health of 100
	Point3D pt(13, 13, 13);
	Player player1("Attacker", &pt, 23, 100);

	// Create an environment
	Environment* env = Environment::getInstance();
	// Generate 10 random entities
	env->generateEntities(10);
	// Print environment and player before attack
	std::cout << "Player before attack: " << std::endl;
	player1.print();
	std::cout << std::endl;
	std::cout << "Environment before attack: " << std::endl;
	env->print();
	std::cout << std::endl;

	// Commence attack
	while (Entity* toAttack = env->getClosestAliveEntity(&player1, Entity::Type::Mob)) {
		// While there are Mobs to attack, attack them
		player1.moveTo(toAttack);
		player1.attack(toAttack);
	}

	// Print environment after attack
	std::cout << "Player after attack: " << std::endl;
	player1.print();
	std::cout << std::endl;
	std::cout << "Environment after attack: " << std::endl;
	env->print();
	std::cout << std::endl;

	return 0;
}