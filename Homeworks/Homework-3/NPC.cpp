#include "NPC.h"
#include <iostream>

NPC::NPC(const string& newName, const Point2D* newLoc) : Entity(newName, newLoc) {

}

void NPC::print() const {
	std::cout << "NPC\t" << "ID: " << getId() << "\t" << "Location: ";
	location->print();
	std::cout << std::endl;
}