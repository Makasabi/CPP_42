#pragma once

#include "PhoneBook.hpp"
#include "main.hpp"
#include "colors.hpp"

class Contact {

public:
	
	Contact();
	~Contact();

	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickName(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;

	bool setFirstName(std::string s);
	bool setLastName(std::string s);
	bool setNickName(std::string s);
	bool setPhoneNumber(std::string s);
	bool setDarkestSecret(std::string s);

private:

	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;

};
