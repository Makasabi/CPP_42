#include "PhoneBook.hpp"
#include "utils.hpp"
#include "Contact.hpp"
#include "colors.hpp"

Contact::Contact(void) {

	return ;
}

Contact::~Contact(void) {

	return ;
}

std::string	Contact::getFirstName(void) const {

	return this->_firstName;
}

std::string	Contact::getLastName(void) const {

	return this->_lastName;
}

std::string	Contact::getNickName(void) const {

	return this->_nickName;
}

std::string	Contact::getPhoneNumber(void) const {

	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret(void) const {

	return this->_darkestSecret;
}

bool Contact::setFirstName(std::string s) {

	if (s.size() > 0)
	{
		this->_firstName = s;
		return 0;
	}
	return 1;
}

bool Contact::setLastName(std::string s){

	if (s.size() > 0)
	{
		this->_lastName = s;
		return 0;
	}
	return 1;
}

bool Contact::setNickName(std::string s) {

	if (s.size() > 0)
	{
		this->_nickName = s;
		return 0;
	}
	return 1;
}

bool Contact::setPhoneNumber(std::string s) {

	if (s.size() > 0)
	{
		this->_phoneNumber = s;
		return 0;
	}
	return 1;
}

bool Contact::setDarkestSecret(std::string s){

	if (s.size() > 0)
	{
		this->_darkestSecret = s;
		return 0;
	}
	return 1;
}