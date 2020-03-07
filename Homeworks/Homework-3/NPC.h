#pragma once

#include "Entity.h"

class NPC : public Entity {
public:
	// Constructor
	NPC(const string& newName = "", const Point2D* newLoc = nullptr);

	// Other methods
	void print() const override;
};