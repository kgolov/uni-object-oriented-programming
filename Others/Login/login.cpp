#include <iostream>
#include "login.h"

Login::Login() : session(0){
	user = new char[5];
	strcpy(user, "test");
	pass = new char[5];
	strcpy(pass, "1234");
}

Login::Login(char* user) : session(1) {
	size_t size = strlen(user);
	this->user = new char[size + 1];
	strcpy(this->user, user);

	size = 0;

	std::cout << "Password length: ";
	std::cin >> size;
	std::cout << std::endl;	

	pass = new char[size + 1];
	std::cout << "Enter password of " << size << "characters: " << std::endl;
	std::cin >> pass;
}

Login::Login(char* user, char* pass) : session(1) {
	size_t size = strlen(user);
	this->user = new char[size + 1];
	strcpy(this->user, user);

	size = strlen(pass);
	this->pass = new char[size + 1];
	strcpy(this->pass, pass);
}

Login::Login(char* user, char* pass, int session) {
	this->session = session;

	size_t size = strlen(user);
	this->user = new char[size + 1];
	strcpy(this->user, user);

	size = strlen(pass);
	this->pass = new char[size + 1];
	strcpy(this->pass, pass);
}

Login::Login(const Login& obj) : session(obj.session) {
	size_t size = strlen(obj.user);
	user = new char[size + 1];
	strcpy(user, obj.user);

	size = strlen(obj.pass);
	pass = new char[size + 1];
	strcpy(pass, obj.pass);
}

Login::~Login() {
	delete[] user;
	delete[] pass;
	session = -1;
}