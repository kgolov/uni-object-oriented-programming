#include "Game.h"
#include <cstring>

GameCharacter::GameCharacter(const char* name, int hp, int mp, int ap, int dp) :
	hp(hp), mp(mp), ap(ap), dp(dp) {
	
	setName(name);
}

GameCharacter::~GameCharacter() {
	delete[] name;
}

GameCharacter::GameCharacter(const GameCharacter& toCopy) :
	hp(toCopy.getHP()), mp(toCopy.getMP()), ap(toCopy.getAP()), dp(toCopy.getDP()) {

	setName(toCopy.getName());
}

GameCharacter& GameCharacter::operator=(const GameCharacter& toCopy) {
	if (this != &toCopy) {
		setName(toCopy.getName());

		hp = toCopy.getHP();
		mp = toCopy.getMP();
		ap = toCopy.getAP();
		dp = toCopy.getDP();
	}
	return *this;
}

void GameCharacter::setName(const char* name) {
	if (name == nullptr) {
		return;
	}

	delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void GameCharacter::getattacked(int attack) {
	if (attack - dp > 0) {
		hp -= attack - dp;
	}
}

void GameCharacter::getattacked(const GameCharacter& attacker) {
	getattacked(attacker.getAP());
}

void GameCharacter::print() const {
	std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const GameCharacter& obj) {
	os << obj.getName() << std::endl;
	os << "HP = " << obj.getHP() << std::endl;
	os << "MP = " << obj.getMP() << std::endl;
	os << "AP = " << obj.getAP() << std::endl;
	os << "DP = " << obj.getDP() << std::endl;

	return os;
}