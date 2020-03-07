#include "PowerUser.h"
#include <cstring>

PowerUser::PowerUser() : User(), reputation(0) {

}

PowerUser::PowerUser
(const char* username, const char* password, const char* title, const char* address, const int rep) :
	User(username, password, title, address), reputation(rep) {

}

void PowerUser::getReputationFrom(const User& from) {
	// User can only give reputation if it is not itself, i.e. their usernames are different
	if (strcmp(this->getUsername(), from.getUsername()) == 0) {
		// Their usernames are not different, so return
		return;
	}

	// The user can give reputation
	reputation++;
}