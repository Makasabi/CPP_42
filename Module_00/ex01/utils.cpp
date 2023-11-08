#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"
#include "colors.hpp"

int		checkName(std::string str) {

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