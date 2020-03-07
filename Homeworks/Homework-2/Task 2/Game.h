#ifndef __GAME_H
#define __GAME_H

#include <iostream>

class GameCharacter {
private:
	char* name = nullptr;
	int hp;
	int mp;
	int ap;
	int dp;

protected:
	GameCharacter(const char* name, int hp, int mp, int ap, int dp);
	~GameCharacter();
	GameCharacter(const GameCharacter& toCopy);
	GameCharacter& operator=(const GameCharacter& toCopy);

	void setName(const char* name);

public:
	void getattacked(int attack);
	void getattacked(const GameCharacter& attacker);

	const char* getName() const { return name; }
	const int getHP() const { return hp; }
	const int getMP() const { return mp; }
	const int getAP() const { return ap; }
	const int getDP() const { return dp; }

	void print() const;
	friend std::ostream& operator<<(std::ostream& os, const GameCharacter& obj);
};

class Warrior : public GameCharacter {
public:
	Warrior() : GameCharacter("Warrior", 20, 5, 4, 1) {

	}
};

class Guardian : public GameCharacter {
public:
	Guardian() : GameCharacter("Guardian", 40, 25, 1, 3) {

	}
};

class Wizzard : public GameCharacter {
public:
	Wizzard() : GameCharacter("Wizzard", 30, 30, 2, 2) {

	}
};

#endif