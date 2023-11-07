#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

class PhoneBook {

public:

	PhoneBook();
	~PhoneBook();

	void		addContact();
	void		searchContact();
	void		exitPhoneBook();

private:

	Contact		_ContactTab[8];
	static int	_IndexContact;
};

#endif