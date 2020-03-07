#ifndef __ADMIN_H
#define __ADMIN_H

#include "PowerUser.h"
#include "VIP.h"

class Admin : public PowerUser, public VIP {
public:
	Admin();
	Admin(const char* username, const char* password, const char* title, const char* address = "");

	// Setters
	void setUsername(const char* username);
	void setUsernameOf(const char* username, User& user);
};

#endif