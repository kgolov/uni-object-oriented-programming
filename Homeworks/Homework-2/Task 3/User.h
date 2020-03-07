#ifndef __USER_H
#define __USER_H

#include "Guest.h"

class User : public Guest {
private:
	void setPassword(const char* password);

protected:
	char* username = nullptr;
	char* encPass = nullptr;
	char* title = nullptr;

	void setUsername(const char* username);
	void setTitle(const char* title);

	friend class Admin;

public:
	User();
	~User();
	User(const User& toCopy);
	User& operator=(const User& toCopy);
	User(const char* username, const char* password, const char* title, const char* address = "");

	// Setters
	void changePassword(const char* oldPass, const char* newPass);

	// Getters
	const char* getUsername() const { return username; }
	const char* getTitle() const { return title; }
};

#endif