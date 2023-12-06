#include "Form.hpp"

Form::Form() : _name("default"), _authograph(false), _gradeSign(100), _gradeExec(50) {

	std::cout << _GREYER << _ITALIC << "Form - Default constructor called" << _END << std::endl;
}

Form::Form(std::string const & name, unsigned char const sign, unsigned char const exec) : _name(name), _authograph(false), _gradeSign(sign), _gradeExec(exec){

	std::cout << _GREYER << _ITALIC << "Form - Parametric constructor called" << _END << std::endl;
	if (sign < 1 || exec < 1)
		throw Form::GradeTooHighException();
	if (sign > 150 || exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src) : _name(src.getName()), _authograph(false), _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec()){

	std::cout << _GREYER << _ITALIC << "Form - Copy constructor called" << _END << std::endl;
}

Form::~Form(void) {

	std::cout << _GREYER << _ITALIC << "Form - destructor called" << _END << std::endl;
}

Form & Form::operator=(Form const & src) {

	(void)src;
	return *this;
}

std::string	Form::getName(void) const {

	return this->_name;
}

bool	Form::getAuthograph(void) const {

	return this->_authograph;
}

unsigned char	Form::getGradeSign(void) const {

	return this->_gradeSign;
}

unsigned char	Form::getGradeExec(void) const {

	return this->_gradeExec;
}

void	Form::beSigned(Bureaucrat const & officer) {

	if (this->_authograph == true)
		throw Form::AlreadySigned();
	if (officer.getGrade() > this->_gradeSign)
		throw Bureaucrat::GradeTooLowException();
	this->_authograph = true;
}

std::ostream & operator<<(std::ostream & o, Form const & rhs) {
	
	o << "-------------------------------------\n" \
	<<_BOLD << "Form name:\t\t" << rhs.getName() << _END\
	<< "\nIs signed:\t\t" << (rhs.getAuthograph()?TRUE:FALSE) \
	<< "\nSignature level:\t" << static_cast<int>(rhs.getGradeSign()) \
	<< "\nExecution level:\t" << static_cast<int>(rhs.getGradeExec()) \
	<< "\n-------------------------------------\n" << std::endl;
	return o;
}