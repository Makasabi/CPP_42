#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Form", 145, 137), _target("target"){

	std::cout << _GREYER << _ITALIC << "ShrubberyCreationForm - Default constructor called" << _END << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("Shrubbery", 145, 137), _target(target){

	std::cout << _GREYER << _ITALIC << "ShrubberyCreationForm - Parametric constructor called" << _END << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

	std::cout << _GREYER << _ITALIC << "ShrubberyCreationForm - Destructor called" << _END << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm("Shrubbery", 145, 137), _target(src.getTarget()){

	std::cout << _GREYER << _ITALIC << "ShrubberyCreationForm - Copy constructor called" << _END << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const {

	return this->_target;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {

	(void)src;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

// call function Execute of Aform in a try {} and catch potential errors here
/*
try {
	AForm::execute(executor);
		// 1. check if already signed.
		// 2. check if Bureaucrat has the correct grade.
	executeform(executor); -> this is a rivate function of class ShrubberyCreationForm;
		// Do what you are supposed to do.
}
catch {
	display error message here;
}*/

}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs) {

	o << "-------------------------------------\n" \
	<<_BOLD << "AForm name:\t\t" << rhs.getName() << _END\
	<< "\nIs signed:\t\t" << (rhs.getAuthograph()?TRUE:FALSE) \
	<< "\nSignature level:\t" << static_cast<int>(rhs.getGradeSign()) \
	<< "\nExecution level:\t" << static_cast<int>(rhs.getGradeExec()) \
	<< "\nTarget;\t\t" << _target \
	<< "\n-------------------------------------\n" << std::endl;
	return o;
}
