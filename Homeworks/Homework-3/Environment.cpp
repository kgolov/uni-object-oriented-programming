#include "Environment.h"
// For rand and srand functions
#include <random>
#include <time.h>

// For singleton implementation
Environment* Environment::instance = nullptr;

Environment::Environment() {

}

Environment::~Environment() {
	// Delete all pointers in the vector
	for (int i = 0; i < entities.size(); i++) {
		delete entities[i];
	}

	// Delete instance
	delete instance;
}

Environment* Environment::getInstance() {
	if (instance == nullptr) {
		instance = new Environment();
	}

	return instance;
}

void Environment::add(Entity* entity) {
	entities.push_back(entity);
}

const Entity* Environment::getAt(const int index) const {
	if (index < 0 || index >= entities.size()) {
		return nullptr;
	}

	return entities[index];
}

const Entity* Environment::operator[](const int index) const {
	return getAt(index);
}

void Environment::removeAt(const int index) {
	if (index < 0 || index >= entities.size()) {
		return;
	}

	delete entities[index];

	entities.erase(entities.begin() + index);
}

void Environment::generateEntities(const int number) {
	if (number <= 0) {
		return;
	}

	// Seed random function generator
	srand(time(NULL));

	for (int i = 0; i < number; i++) {
		// Determine type of entity
		Entity::Type type = static_cast<Entity::Type>(rand() % 3);

		// Generate a location - Point2D or Point 3D
		Point2D* location;
		bool _3d = rand() % 2;
		if (_3d) {
			location = new Point3D(rand() % 100, rand() % 100, rand() % 100);
		}
		else {
			location = new Point2D(rand() % 100, rand() % 100);
		}

		// Generate number for damage - if the type is NPC, it will not be used, but this is not a problem
		// Maximum damage is 25, minimum is 1
		int damage = (rand() % 25) + 1;
		// Let all characters start with max health
		int health = MAX_HEALTH;

		// Finally, generate the required entity and push it into the vector
		Entity* generated = Entity::createEntity(type, location, damage, health);
		entities.push_back(generated);

		delete location;
	}
}

void Environment::destroyEntities() {
	// Delete all pointers in the vector
	for (int i = 0; i < entities.size(); i++) {
		delete entities[i];
	}

	// Clear the vector
	entities.clear();
}

Entity* Environment::getClosestAliveEntity(const Player* player, Entity::Type type) const {
	Entity* closest = nullptr;
	int leastDistance = INT_MAX;

	for (int i = 0; i < entities.size(); i++) {
		if (entities[i] == player || !entities[i]->isAlive() || entities[i]->getType() != type) {
			continue;
		}

		// If we are here, the current entity is of the required type, and is not the argument player in question
		// and it is alive
		int currentDistance = player->getDistanceTo(entities[i]);
		if (currentDistance < leastDistance) {
			// The current entity is closer than the closest by now
			leastDistance = currentDistance;
			closest = entities[i];
		}
	}

	// We have found the closest alive entity of the required type
	// If it is nullptr - such does not exist
	return closest;
}

void Environment::print() const {
	for (int i = 0; i < entities.size(); i++) {
		entities[i]->print();
	}
}