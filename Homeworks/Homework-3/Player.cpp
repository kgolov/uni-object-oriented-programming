#include "Player.h"
#include <iostream>

Player::Player(const string& newName, const Point2D* newLoc, const int damage, const int health) :
	Entity(newName, newLoc), damage(damage), health(health) {

	setType(Type::Player);
}

const bool Player::isAlive() const {
	return health > 0;
}

void Player::makeDamage(const int toTake) {
	health -= toTake;

	if (health < 0) {
		health = 0;
	}
}

void Player::print() const {
	std::cout << "Player\t" << "ID: " << getId() << "\t" << "Location: ";
	location->print();
	std::cout << "\t" << "Health:" << getHealth() << "\t" << "Damage: " << getDamage() << std::endl;
}

void Player::attack(Entity* entity) const {
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