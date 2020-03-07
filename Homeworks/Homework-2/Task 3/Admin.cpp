#include "Admin.h"

Admin::Admin() : User() {

}

Admin::Admin(const char* username, const char* password, const char* title, const char* address) :
	User(username, password, title, address) {

}

void Admin::setUsername(const char* username) {
	User::setUsername(username);
}

void Admin::setUsernameOf(const char* username, User& user) {
	user.setUsername(username);
}