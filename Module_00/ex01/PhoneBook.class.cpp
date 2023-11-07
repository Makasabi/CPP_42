#include <iostream>
#include <cctype>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include "Colors.hpp"

PhoneBook::PhoneBook(void) {
	
	return ;
}

PhoneBook::~PhoneBook(void) {

	return ;
}

void	printError(std::string str) {

	std::cout << _MAGENTA << str << _END << std::endl;
	return;
}

int		checkName(std::string str){

	for(int i = 0; str[i]; i++){
		if (std::isalpha(str[i]) || str[i] == '\''
			|| str[i] == ' ' || str[i] == '-')
			continue;
		else
			return (1);
	}
	return (0);
}

int		checkPhone(std::string str) {

	for(int i = 0; str[i]; i++){
		if (std::isdigit(str[i]) || str[i] == '+' || str[i] == ' '
			|| str[i] == '-' || str[i] == '(' || str[i] == ')')
			continue;
		else
			return (1);
	}
	return (0);
}

std::string	getData(std::string str) {

	std::string buff;
	std::string error;


	std::cout << _BOLD << "Contact's " << str << _END << std::endl;
	while (buff.empty())
	{
		std::getline(std::cin, buff);
		if (std::cin.eof())
		{
			printError("Bad decision");
			return error;
		}
	}
	if (str == "First Name" || str == "Last Name" || str == "Nickname") {
		if (checkName(buff)) {
			printError("Wrong format");
			return error;
		}
	}
	else if (str == "Phone Number") {
		if (checkPhone(buff)) {
			printError("Wrong format");
			return error;	
		}
	}
	return buff;
}

void	PhoneBook::addContact( void ) {

	std::string buff;

	buff =	getData("First Name");
	if (buff.empty())
		return ;
	_ContactTab[_IndexContact].setFirstName(buff);

	buff =	getData("Last Name");
	if (buff.empty())
		return ;
	_ContactTab[_IndexContact].setLastName(buff);

	buff =	getData("Nickname");
	if (buff.empty())
		return ;
	_ContactTab[_IndexContact].setNickName(buff);

	buff =	getData("Phone Number");
	if (buff.empty())
		return ;
	_ContactTab[_IndexContact].setPhoneNumber(buff);

	buff =	getData("Darkest Secret");
	_ContactTab[_IndexContact].setDarkestSecret(buff);

	if (this->_IndexContact < 7)
		_IndexContact++;
	else if (this->_IndexContact == 7)
		_IndexContact = 0;
}

void	PhoneBook::searchContact( void ) {
// affiche les contacts enregistre's sous la forme d'une liste de 4 colonnes

}

void	PhoneBook::exitPhoneBook( void ) {

}

int	PhoneBook::_IndexContact = 0;