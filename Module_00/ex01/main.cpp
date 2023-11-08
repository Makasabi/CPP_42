#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"
#include "colors.hpp"

void	printError(std::string str) {

	std::cout << _MAGENTA << str << _END << std::endl;
	// exit (EXIT_FAILURE);
	return;
}

int main(void) {

	PhoneBook	PhoneBook;
	std::string	buff;
	bool		b = 0;

	std::cout << _BOLD << _LAGOON << "\nWelcome to your phonebook!" << _END << std::endl;
	while (1){
		if (b == 0){
			std::cout << _BOLD << "\nMENU\nYou can either ADD or SEARCH for a contact, or EXIT the phonebook" << _END << std::endl;
			std::cout << "Type a command:\n" << std::endl;
		}
		std::cin >> buff;
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
