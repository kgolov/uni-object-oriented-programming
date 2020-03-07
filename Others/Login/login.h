#ifndef __LOGIN_H
#define __LOGIN_H

class Login {
private:
	char* user;
	char* pass;
	int session;

public:
	Login();
	Login(char* user);
	Login(char* user, char* pass);
	Login(char* user, char* pass, int session);
	Login(const Login& obj);

	~Login();


};

#endif