#include "Entity.h"
#include "Player.h"
#include "Mob.h"
#include "NPC.h"

Entity::Entity(const string& newName, const Point2D* newLoc) {
	id = ++counter;
	setName(newName);
	moveTo(newLoc);
}

Entity::~Entity() {
	delete location;
}

void Entity::setName(const string& newName) {
	if (newName == "") {
		// generate name based on ID
		name = "Entity" + std::to_string(id); 
	}
	else {
		name = newName;
	}
}

void Entity::setType(Type newType) {
	type = newType;
}

const string& Entity::getName() const {
	return name;
}

const Point2D* Entity::getLocation() const {
	return location;
}

const Entity::Type Entity::getType() const {
	return type;
}

const unsigned long long Entity::getId() const {
	return id;
}

const bool Entity::isAlive() const {
	return true;
}

const double Entity::getDistanceTo2D(const Entity* entity) const {
	if (entity == nullptr) {
		return 0;
	}
	return location->getDistanceTo(*(entity->location));
}

const double Entity::getDistanceTo(const Entity* entity) const {
	if (entity == nullptr) {
		return 0;
	}

	// If we have stored a Point2D either in *this, or in entity, treat all points like Point2D
	if (dynamic_cast<Point3D*>(location) == nullptr ||
		dynamic_cast<Point3D*>(entity->location) == nullptr) {
		return getDistanceTo2D(entity);
	}
	
	// Calculate distance between two Point3Ds, only if such are stored in *this and entity.
	return dynamic_cast<Point3D*>(location)->getDistanceTo(*((Point3D*)entity->location));
}

void Entity::moveTo(const Point2D* point) {
	if (point == nullptr) {
		return;
	}

	const Point3D* ptr = dynamic_cast<const Point3D*>(point);

	delete location;

	if (ptr != nullptr) {
		location = new Point3D(*ptr); // Successfully cast to Point3D
	}
	else {
		location = new Point2D(*point); // Cast failed so treat it as Point2D
	}
}

void Entity::moveTo(const Entity* entity) {
	if (entity == nullptr) {
		return;
	}

	moveTo(entity->location);
}

Entity* Entity::createEntity(const Entity::Type type,
	const Point2D* location, const int damage, const int health, const string& name) {

	if (type == Type::Player) {
		return new Player(name, location, damage, health);
	}
	else if (type == Type::NPC) {
		return new NPC(name, location);
	}
	else if (type == Type::Mob) {
		return new Mob(name, location, damage, health);
	}
	else {
		return nullptr;
	}	
}