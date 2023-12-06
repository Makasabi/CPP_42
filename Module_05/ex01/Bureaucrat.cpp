#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Karen"), _grade(75) {

	std::cout << _GREYER << _ITALIC << "Bureaucrat - Default constructor called" << _END << std::endl;
};

Bureaucrat::Bureaucrat(std::string const & name, unsigned char const grade) : _name(name) {

	std::cout << _GREYER << _ITALIC << "Bureaucrat - Parametric constructor called" << _END << std::endl;
	try {
		Bureaucrat::setGrade(grade);
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
		if (grade == 0)
			_grade = 1;
		else{
			_grade = 150;
		}
		std::cout << _ORANGE << _name << "'s grade set at default value of " << static_cast<int>(_grade) << _END << std::endl;
	}
}

Bureaucrat::~Bureaucrat() {

	std::cout << _GREYER << _ITALIC << "Bureaucrat - Destructor called" << _END << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName()){

	std::cout << _GREYER << _ITALIC << "Bureaucrat - Copy constructor called" << _END << std::endl;
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src) {

	this->_grade = src.getGrade();
	return *this;
}

std::string	Bureaucrat::getName(void) const {

	return this->_name;
}

unsigned char	Bureaucrat::getGrade(void) const {

	return this->_grade;
}

void	Bureaucrat::setGrade(unsigned char const grade) {

	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
}

void Bureaucrat::incrementGrade() {

	std::cout << _GREYER << _YELLOW << "Increment Grade of " << _name << " by 1 called" << _END << std::endl;
	try {
		this->setGrade(this->getGrade() - 1);
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
	}
	std::cout << "❯❯❯ " << *this;
}

void Bureaucrat::incrementGrade(unsigned char const inc) {

	std::cout << _GREYER << _YELLOW << "Increment Grade of " << _name << " by " << static_cast<int>(inc) << " called" << _END << std::endl;
	try {
		this->setGrade(this->getGrade() - inc);
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
	}
	std::cout << "❯❯❯ " << *this;
}

void Bureaucrat::decrementGrade() {

	std::cout << _GREYER << _YELLOW << "Decrement Grade of " << _name << " by 1 called" << _END << std::endl;
	try {
		this->setGrade(this->getGrade() + 1);
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
	}
	std::cout << "❯❯❯ " << *this;
}

void Bureaucrat::decrementGrade(unsigned char const dec) {

	std::cout << _GREYER << _YELLOW << "Decrement Grade of " << _name << " by " << static_cast<int>(dec) << " called" << _END << std::endl;
	try {
		this->setGrade(this->getGrade() + dec);
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
	}
	std::cout << "❯❯❯ " << *this;
}

void Bureaucrat::signForm(Form & paper) {

	try {
		paper.beSigned(*this);
		std::cout << _FOREST_GREEN << this->_name << " signed " << paper.getName() << _END << std::endl;
	}
	catch (std::exception& ex) {
		std::cout << this->_name << " couldn't sign " << paper.getName() << " because " << ex.what();
	}
}


std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {
	
	o << rhs.getName() << ", bureaucrat grade " << static_cast<int>(rhs.getGrade()) << std::endl;
	return o;
}