#pragma once

# include "Contact.hpp"
# include "utils.hpp"
# include "colors.hpp"

class PhoneBook {

public:

	PhoneBook();
	~PhoneBook();

	void		addContact();
	void		searchContact();
	void		exitPhoneBook();

	void		displayContacts();

private:

	Contact		_ContactTab[8];
	static int	_IndexContact;
};
