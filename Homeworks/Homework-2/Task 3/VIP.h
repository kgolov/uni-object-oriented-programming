#ifndef __VIP_H
#define __VIP_H

#include "User.h"

class VIP : virtual public User {
public:
	VIP();
	VIP(const char* username, const char* password, const char* title, const char* address = "");

	// Setters
	void setTitle(const char* title);
};

#endif