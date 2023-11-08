#pragma once

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <cctype>
# include "colors.hpp"
# include "Contact.hpp"
# include "PhoneBook.hpp"

class Contact;

int			checkName(std::string str);
int			checkPhone(std::string str);
void		printError(std::string str);
void		ResizeAndDispay(std::string buff);
void		printContact(Contact contact);
std::string	getData(std::string str);