#ifndef __USER_H
#define __USER_H

struct Date {
	int day;
	int month;
	int year;

	inline bool operator!=(const Date& toCompare) const;
};

const Date UNDEF_DATE = { 1, 1, 1870 };
const char UNDEF_GENDER = 'U';

class User {
	char* name;
	Date born;
	char gender;
	
public:
	// Constructors and destructors
	User();
	User(const char* name, Date birthDate, const char gender);
	User(const char gender);
	User(Date birthDate);
	User(const User& rhs);

	~User();

	// Getters
	char* getName() const;
	Date getBirth() const;
	char getGender() const;

	// Setters
	bool setName(const char* name);
	bool setDate(Date birthDate);
	bool setGender(const char gender);

	// Other functions
	bool isDefined() const;

	// Private functions
private:
	bool isValidGender(const char gender) const;
	bool isValidDate(Date date) const;	
};

#endif