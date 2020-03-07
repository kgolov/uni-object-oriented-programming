#include "VIP.h"

VIP::VIP() : User() {

}

VIP::VIP(const char* username, const char* password, const char* title, const char* address) :
	User(username, password, title, address) {

}

void VIP::setTitle(const char* title) {
	User::setTitle(title);
}