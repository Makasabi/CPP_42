#pragma once

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <cctype>
# include "PhoneBook.hpp"
# include "Contact.hpp"
# include "colors.hpp"

class Contact;

std::string	getData(std::string str);
int		checkName(std::string str);
int		checkPhone(std::string str);
void	ResizeAndDispay(std::string buff);
void	printContact(Contact contact);
void	printError(std::string str);