#include "Mob.h"
#include <iostream>

Mob::Mob(const string& newName, const Point2D* newLoc, const int damage, const int health) :
	Entity(newName, newLoc), damage(damage), health(health) {

	setType(Type::Mob);
}

const bool Mob::isAlive() const {
	return health > 0;
}

void Mob::makeDamage(const int toTake) {
	health -= toTake;
	
	if (health < 0) {
		health = 0;
	}
}

void Mob::print() const {
	std::cout << "Mob\t" << "ID: " << getId() << "\t" << "Location: ";
	location->print();
	std::cout << "\t" << "Health:" << getHealth() << "\t" << "Damage: " << getDamage() << std::endl;
}

void Mob::attack(Entity* entity) const {
	if (entity == nullptr) {
		return;
	}

	if (entity->getType() == Type::Player) {
		if (getDistanceTo(entity) < 5) {
			dynamic_cast<Player*>(entity)->makeDamage(damage);
		}
	}
	if (entity->getType() == Type::Mob) {
		if (getDistanceTo(entity) < 5) {
			dynamic_cast<Mob*>(entity)->makeDamage(damage);
		}
	}
}