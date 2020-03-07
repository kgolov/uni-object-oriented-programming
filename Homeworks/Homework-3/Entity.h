#pragma once

#include "Point3D.h"
#include <string>
using std::string;

// All entities will start with this health
static const int MAX_HEALTH = 100;

static unsigned long long counter = 0;

class Entity {
public:
	enum class Type {
		Player,
		NPC,
		Mob
	};

protected:
	unsigned long long id;
	string name;
	Point2D* location = nullptr;
	Type type;

	// Setters
	void setName(const string& newName);
	void setType(Type newType);

public:
	// Factory design
	static Entity* createEntity(const Type type, const Point2D* location, const int health = 0, const int damage = 0,
		const string& name = "");

	// Constructor, virtual destructor because this is a base class
	Entity(const string& newName = "", const Point2D* newLoc = nullptr);
	virtual ~Entity();

	// Delete copy constructor and operator=, because every object must be unique
	Entity(const Entity&) = delete;
	Entity& operator=(const Entity&) = delete;

	// Required methods by task
	virtual const bool isAlive() const;
	const double getDistanceTo2D(const Entity* entity) const;
	const double getDistanceTo(const Entity* entity) const;

	void moveTo(const Point2D* point);
	void moveTo(const Entity* entity);

	// Getters
	const string& getName() const;
	const Point2D* getLocation() const;
	const Type getType() const;
	const unsigned long long getId() const;

	virtual void print() const = 0;	
};