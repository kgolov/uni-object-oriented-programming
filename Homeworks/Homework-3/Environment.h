#pragma once

#include "Player.h"
#include "Mob.h"
#include "NPC.h"
#include <vector>
using std::vector;

class Environment {
	// Implementation as a Singleton
	static Environment* instance;
	Environment();

	vector<Entity*> entities;

public:
	// Will play role as a constructor
	static Environment* getInstance();
	~Environment();

	// We cannot have copy constructor or operator=, because of the implementation as a Singleton
	Environment(const Environment&) = delete;
	Environment& operator=(const Environment&) = delete;

	// Methods required by task
	void add(Entity* entity);
	const Entity* getAt(const int index) const;
	const Entity* operator[](const int index) const;
	void removeAt(const int index);
	void generateEntities(const int number);
	void destroyEntities();
	Entity* getClosestAliveEntity(const Player* player, Entity::Type type) const;
	void print() const;
};