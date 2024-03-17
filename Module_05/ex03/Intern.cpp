#include "Intern.hpp"

t_maker const Intern::_search[] = {
	{std::string("robotomy request"), &Intern::makeRRF},
	{std::string("presidential pardon"), &Intern::makePPF},
	{std::string("shrubbery creation"), &Intern::makeSCF},
	{std::string(""), NULL},
};

Intern::Intern() {

	std::cout << _GREYER << _ITALIC << "Intern - Default constructor called" << _END << std::endl;
}

Intern::~Intern() {

	std::cout << _GREYER << _ITALIC << "Intern - Destructor called" << _END << std::endl;
}

Intern::Intern(Intern const & src){

	*this = src;
	std::cout << _GREYER << _ITALIC << "Intern - Copy constructor called" << _END << std::endl;
}

Intern & Intern::operator=(Intern const & src) {

	(void)src;
	return *this;
}

AForm * Intern::makePPF(std::string const & src) const {

	AForm * form = new PresidentialPardonForm(src);
	return form;
}

AForm * Intern::makeRRF(std::string const & src) const {

	AForm * form = new RobotomyRequestForm(src);
	return form;
}

AForm * Intern::makeSCF(std::string const & src) const {

	AForm * form = new ShrubberyCreationForm(src);
	return form;
}

AForm * Intern::makeForm(std::string const & formName, std::string const & target){

	for (int i = 0; this->_search[i].key.size() != 0; i++)
		if (formName == this->_search[i].key) {
			std::cout << _CYAN << "Intern creates form: " << _BOLD << formName << _END << std::endl;
			return ((this->*Intern::_search[i].functionPointer)(target));
		}
	throw FormNotRecognised();
	return NULL;
}

