#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "main.hpp"
#include "colors.hpp"


std::string	getData(std::string str) {

	std::string buff;
	std::string name = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz \'-";
	std::string phone = " 0123456789+-.()";

	std::cout << _BOLD << "Contact's " << str << _END << std::endl;
	while (buff.size() == 0) {
		std::getline(std::cin, buff);
		if (std::cin.eof())
			printError("Bad decision");
	}
	if (str == "First Name" || str == "Last Name" || str == "Nickname") {
		if ((buff.find_first_not_of(name) != std::string::npos)) {
			std::cout << _MAGENTA << "Wrong format" << _END << std::endl;
			buff = getData(str);
		}
	}
	else if (str == "Phone Number") {
		if ((buff.find_first_not_of(phone) != std::string::npos)) {
			std::cout << _MAGENTA << "Wrong format" << _END << std::endl;
			buff = getData(str);	
		}
	}
	return buff;
}

void	ResizeAndDispay(std::string buff) {

	if (buff.size() <= 10)
		std::cout << "|" << std::setw(10) << buff;
	else {
		buff.resize(9);
		buff.resize(10, '.');
		std::cout << "|" << std::setw(10) << buff;
	}
}

void	printContact(Contact contact) {

	std::cout << "---------------------------------------------" <<std::endl;
	std::cout << _BOLD << "First Name\t" << _END << contact.getFirstName() << std::endl;
	std::cout << _BOLD << "Last Name\t" << _END << contact.getLastName() << std::endl;
	std::cout << _BOLD << "Nickname\t" << _END << contact.getNickName() << std::endl;
	std::cout << _BOLD << "Phone Number\t" << _END << contact.getPhoneNumber() << std::endl;
	std::cout << _BOLD << "Darkest Secret\t" << _END << contact.getDarkestSecret() << std::endl;
	std::cout << "---------------------------------------------" <<std::endl;
}

void	printError(std::string str) {

	std::cout << _MAGENTA << str << _END << std::endl;
	exit (EXIT_FAILURE);
}

int main(void) {

	PhoneBook	PhoneBook;
	std::string	buff;
	bool		b = 0;

	std::cout << _BOLD << _LAGOON << "\nWelcome to Minitel!" << _END << std::endl;
	while (1){
		if (b == 0){
			std::cout << _BOLD << "\nMENU\nYou can either ADD or SEARCH for a contact, or EXIT Minitel" << _END << std::endl;
			std::cout << "Type a command:\n" << std::endl;
		}
		std::getline(std::cin, buff);
		if (std::cin.eof())
		{
			printError("Bad decision!");
			return 1;
		}
		std::cout << std::endl;
		if (buff == "ADD") {
			b = 0;
			PhoneBook.addContact();
		}
		else if (buff == "SEARCH"){
			b = 0;
			PhoneBook.searchContact();
		}
		else if (buff == "EXIT"){
			b = 0;
			PhoneBook.exitPhoneBook();
		}
		else {
			b = 1;
			continue;
		}
	}
	return 0;
}
