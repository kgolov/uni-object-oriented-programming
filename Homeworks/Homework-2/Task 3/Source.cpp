#include <iostream>
#include "Admin.h"

int main() {
	// Guest user does not have functionality
	Guest guest("127.0.0.1");

	// User has some functionality
	User user1("user1", "password1", "title1", "1.1.1.1");
	// User can change his password
	// USE DEBUGGER HERE TO SEE IF THE METHOD WORKS PROPERLY
	user1.changePassword("password1", "newpassword1");
	// User cannot change his username / title
	// user1.setTitle("title2");
	// user1.setUsername("username2");

	// Power User functionality
	PowerUser pw1("user2", "password2", "title2", "2.2.2.2");
	// Power User can change his password
	pw1.changePassword("password2", "newpassword2");
	// Power User cannot change his username / title
	// pw1.setTitle("title");
	// pw1.setUsername("username");
	// Power User can receive reputation from other users
	pw1.getReputationFrom(user1);
	std::cout << "Power User reputation: " << pw1.getReputation() << ", expected 1" << std::endl;

	// VIP functionality
	VIP vip1("user3", "password3", "title3", "3.3.3.3");
	// VIP can change his title
	vip1.setTitle("newTitle");
	std::cout << "VIP title: " << vip1.getTitle() << ", expected newTitle" << std::endl;
	// VIP cannot change his username
	// vip1.setUsername("newUser");

	// Admin functionality
	Admin admin("admin", "pass", "admin", "4.4.4.4");
	// Admin can change his title
	admin.setTitle("newAdmin");
	std::cout << "Admin title: " << admin.getTitle() << ", expected newAdmin" << std::endl;
	// Admin can change his username
	admin.setUsername("administrator");
	std::cout << "Admin username: " << admin.getUsername() << ", expected administrator" << std::endl;
	// Admin can change username of other users
	admin.setUsernameOf("newVip", vip1);
	std::cout << "VIP username: " << vip1.getUsername() << ", expected newVip" << std::endl;

	return 0;
}