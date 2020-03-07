#pragma once

#include "Entity.h"
#include "Mob.h"

class Player : public Entity {
	int damage;
	int health;

	friend class Mob;
	void makeDamage(const int toTake);

public:
	// Constructor
	Player(const string& newName = "", const Point2D* newLoc = nullptr, const int damage = 0, const int health = 0);

	// Methods as per task
	const bool isAlive() const override;
	void attack(Entity* entity) const;

	// Other methods
	void print() const override;

	// Getters
	const int getDamage() const { return damage; }
	const int getHealth() const { return health; }
};