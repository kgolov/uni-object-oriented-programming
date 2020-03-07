#include <iostream>
#include "user.h"

inline bool Date::operator!=(const Date& toCompare) const {
	return this->day != toCompare.day || this->month != toCompare.month || this->year != toCompare.year;
}

User::User() {
	name = nullptr;
	born = UNDEF_DATE;
	gender = UNDEF_GENDER;
}

User::User(const char* name, Date birthDate = UNDEF_DATE, const char gender = UNDEF_GENDER) {
	setName(name);
	if (!setDate(birthDate)) {
		setDate(UNDEF_DATE);
	}
	if (!setGender(gender)) {
		setGender(UNDEF_GENDER);
	}
}

User::User(const char gender) : name(nullptr), born(UNDEF_DATE) {
	if (!setGender(gender)) {
		setGender(UNDEF_GENDER);
	}
}

User::User(Date birthDate) : name(nullptr), gender(UNDEF_GENDER) {
	if (!setDate(birthDate)) {
		setDate(UNDEF_DATE);
	}
}

User::User(const User& rhs) : born(rhs.born), gender(rhs.gender) {
	setName(rhs.name);
}

User::~User() {
	delete[] name;
	name = nullptr;
	born = UNDEF_DATE;
	gender = UNDEF_GENDER;
}

char* User::getName() const {
	return name;
}

Date User::getBirth() const {
	return born;
}

char User::getGender() const {
	return gender;
}

bool User::isValidGender(const char gender) const{
	return gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F' || gender == UNDEF_GENDER;
}

bool User::isValidDate(Date date) const{
	bool flag = true;

	if (date.year < UNDEF_DATE.year || date.year > 2019) {
		flag = false;
	}

	switch (date.month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (date.day < 1 || date.day > 31) {
				flag = false;
			}
			break;
		case 2:
			if (date.day < 1 || date.day > 28) {
				flag = false;
			}
			break;
		case 4: case 6: case 9: case 11:
			if (date.day < 1 || date.day > 30) {
				flag = false;
			}
			break;
		default:
			flag = false;
	}

	return flag;
}

bool User::setName(const char* name) {
	size_t size;

	for (size = 0; name[size] != '\0'; size++);

	this->name = new char[size + 1]; // To accommodate the terminating zero

	// Copy the user name into our new array
	for (size_t i = 0; i < size; i++) {
		this->name[i] = name[i];
	}
	this->name[size] = '\0';

	return true;
}

bool User::setDate(Date birthDate) {
	if (!isValidDate(birthDate)) {
		std::cerr << "Trying to set invalid birth date!" << std::endl;
		return false;
	}

	this->born = birthDate;
	return true;
}

bool User::setGender(const char gender) {
	if (!isValidGender(gender)) {
		std::cerr << "Trying to set invalid gender!" << std::endl;
		return false;
	}

	if (gender >= 'a' && gender <= 'z') {
		this->gender = gender - 'a' + 'A';
	}
	else {
		this->gender = gender;
	}

	return true;
}

bool User::isDefined() const {
	return name != nullptr && born != UNDEF_DATE && gender != UNDEF_GENDER;
}