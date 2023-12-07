#include "AForm.hpp"

AForm::AForm() : _name("default"), _authograph(false), _gradeSign(100), _gradeExec(50) {

	std::cout << _GREYER << _ITALIC << "AForm - Default constructor called" << _END << std::endl;
}

AForm::AForm(std::string const & name, unsigned char const sign, unsigned char const exec) : _name(name), _authograph(false), _gradeSign(sign), _gradeExec(exec){

	std::cout << _GREYER << _ITALIC << "AForm - Parametric constructor called" << _END << std::endl;
	if (sign < 1 || exec < 1)
		throw AForm::GradeTooHighException();
	if (sign > 150 || exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src) : _name(src.getName()), _authograph(false), _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec()){

	std::cout << _GREYER << _ITALIC << "AForm - Copy constructor called" << _END << std::endl;
}

AForm::~AForm(void) {

	std::cout << _GREYER << _ITALIC << "AForm - destructor called" << _END << std::endl;
}

AForm & AForm::operator=(AForm const & src) {

	(void)src;
	return *this;
}

std::string	AForm::getName(void) const {

	return this->_name;
}

bool	AForm::getAuthograph(void) const {

	return this->_authograph;
}

unsigned char	AForm::getGradeSign(void) const {

	return this->_gradeSign;
}

unsigned char	AForm::getGradeExec(void) const {

	return this->_gradeExec;
}

void	AForm::beSigned(Bureaucrat const & officer) {

	if (this->_authograph == true)
		throw AForm::AlreadySigned();
	if (officer.getGrade() > this->_gradeSign)
		throw Bureaucrat::GradeTooLowException();
	this->_authograph = true;
}

void	AForm::execute(Bureaucrat const & executor) const {

	if (this->_authograph == false)
		throw AForm::NotSigned();
	if (executor.getGrade() > this->_gradeExec)
		throw AForm::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs) {
	
	o << "-------------------------------------------------\n" \
	<<_BOLD << "AForm name:\t\t" << rhs.getName() << _END\
	<< "\nIs signed:\t\t" << (rhs.getAuthograph()?TRUE:FALSE) \
	<< "\nSignature level:\t" << static_cast<int>(rhs.getGradeSign()) \
	<< "\nExecution level:\t" << static_cast<int>(rhs.getGradeExec()) \
	<< "\n-------------------------------------------------\n" << std::endl;
	return o;
}