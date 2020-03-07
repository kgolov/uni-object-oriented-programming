#ifndef __POWER_USER_H
#define __POWER_USER_H

#include "User.h"

class PowerUser : virtual public User {
protected:
	int reputation;

public:
	PowerUser();
	PowerUser(const char* username, const char* password, const char* title, const char* address = "", const int rep = 0);

	void getReputationFrom(const User& from);

	// Getters
	const int getReputation() const { return reputation; }
};

#endif