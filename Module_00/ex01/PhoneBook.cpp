#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "main.hpp"
#include "colors.hpp"

PhoneBook::PhoneBook(void) {
	
	return ;
}

PhoneBook::~PhoneBook(void) {

	return ;
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
	
	std::cout << _CYAN << "\nContact added!\n" << _END << std::endl;
}

void	PhoneBook::displayContacts( void ) {

	std::cout << "---------------------------------------------" <<std::endl;
	std::cout << _BOLD << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname" << "|" << _END << std::endl;
	std::cout << "---------------------------------------------" <<std::endl;

	for (int i = 0; i < 8; i++) {
		std::cout << "|" << std::setw(10) << i;
		ResizeAndDispay(_ContactTab[i].getFirstName());
		ResizeAndDispay(_ContactTab[i].getLastName());
		ResizeAndDispay(_ContactTab[i].getNickName());
		std::cout << "|" << std::endl;
	}
	std::cout << "---------------------------------------------\n" <<std::endl;
}

void	PhoneBook::searchContact( void ) {

	std::string	buff;
	displayContacts();
	std::cout << _BOLD _CYAN << "Select an index between 0 & 7 to display a contact:\n" << _END << std::endl;
	while (buff.size() == 0) {
		std::getline(std::cin, buff);
		if (std::cin.eof())
			printError("Bad decision!");
	}
	std::cout << std::endl;
	if (buff[0] < '0' || buff[0] > '7' || atoi(buff.c_str()) < 0 || atoi(buff.c_str()) > 7)
		std::cout << _MAGENTA << "Bad request!" << _END << std::endl;
	else
		printContact(_ContactTab[atoi(buff.c_str())]);
}

void	PhoneBook::exitPhoneBook( void ) {

	std::cout << _BOLD << _LAGOON << "Bye bye Minitel!" << _END << std::endl;
	std::cout << _LAGOON << _GREYER << "All contact data erased" << _END << std::endl;
	exit (EXIT_FAILURE);
}

int	PhoneBook::_IndexContact = 0;