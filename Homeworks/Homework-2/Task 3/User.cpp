#include "User.h"
#include <cstring>
#include <iostream>

// Basic function for password encryption
static char* passEncrypt(const char* toEncrypt) {
	char* encrypted = new char[strlen(toEncrypt) + 1];
	strcpy_s(encrypted, strlen(toEncrypt) + 1, toEncrypt);

	for (int i = 0; encrypted[i] != '\0'; i++) {
		if (encrypted[i] >= 32 && encrypted[i] <= 63) {
			encrypted[i] += 10;
		}
		else if (encrypted[i] >= 64 && encrypted[i] <= 111) {
			encrypted[i] += 15;
		}
		else if (encrypted[i] >= 112 && encrypted[i] <= 121) {
			encrypted[i] -= 80;
		}
		else if (encrypted[i] >= 122 && encrypted[i] <= 126) {
			encrypted[i] -= 48;
		}
	}

	return encrypted;
}

User::User() : Guest() {
	setUsername("");
	setTitle("");
	setPassword("");
}

User::~User() {
	delete[] username;
	delete[] title;
	delete[] encPass;
}

User::User(const User& toCopy) : Guest(toCopy.getIP()) {
	setUsername(toCopy.getUsername());
	setTitle(toCopy.getTitle());
	setPassword(toCopy.encPass);
}

User& User::operator=(const User& toCopy) {
	if (this != &toCopy) {
		setIP(toCopy.getIP());
		setUsername(toCopy.getUsername());
		setTitle(toCopy.getTitle());
		setPassword(toCopy.encPass);
	}
	return *this;
}

User::User(const char* username, const char* password, const char* title, const char* address) : Guest(address) {
	setUsername(username);
	setTitle(title);

	char* encryptedPass = passEncrypt(password);
	setPassword(encryptedPass);
	delete[] encryptedPass;
}

void User::setPassword(const char* password) {
	if (password == nullptr) {
		return;
	}

	delete[] encPass;

	encPass = new char[strlen(password) + 1];
	strcpy_s(encPass, strlen(password) + 1, password);
}

void User::setUsername(const char* username) {
	if (username == nullptr) {
		return;
	}

	delete[] this->username;

	this->username = new char[strlen(username) + 1];
	strcpy_s(this->username, strlen(username) + 1, username);
}

void User::setTitle(const char* title) {
	if (title == nullptr) {
		return;
	}

	delete[] this->title;

	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);
}

void User::changePassword(const char* oldPass, const char* newPass) {
	if (oldPass == nullptr || newPass == nullptr) {
		return;
	}

	char* encryptedOld = passEncrypt(oldPass);
	// If the given old and the saved passwords do not match, do not change anything!
	if (strcmp(encPass, encryptedOld) != 0) {
		std::cout << "Old password is not correct!" << std::endl;

		delete[] encryptedOld;

		return;
	}
	delete[] encryptedOld;

	// Else, save the new encrypted password
	char* encryptedNew = passEncrypt(newPass);
	setPassword(encryptedNew);
	delete[] encryptedNew;
}