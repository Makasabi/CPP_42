#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form", 25, 5), _target("target"){

	std::cout << _GREYER << _ITALIC << "PresidentialPardonForm - Default constructor called" << _END << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("Presidential Pardon Form", 25, 5), _target(target){

	std::cout << _GREYER << _ITALIC << "PresidentialPardonForm - Parametric constructor called" << _END << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {

	std::cout << _GREYER << _ITALIC << "PresidentialPardonForm - Destructor called" << _END << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm("Presidential Pardon Form", 25, 5), _target(src.getTarget()){

	std::cout << _GREYER << _ITALIC << "PresidentialPardonForm - Copy constructor called" << _END << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const {

	return this->_target;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {

	(void)src;
	return *this;
}

void	PresidentialPardonForm::doAction(void) const {

	std::cout << _GOLD << _BOLD << _UNDER << this->_target << " has been pardonned by Zaphod Beeblebrox" << _END << std::endl;
}