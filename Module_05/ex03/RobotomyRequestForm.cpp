#include "RobotomyRequestForm.hpp"
#include <time.h>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45), _target("target"){

	std::cout << _GREYER << _ITALIC << "RobotomyRequestForm - Default constructor called" << _END << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("Robotomy Request Form", 72, 45), _target(target){

	std::cout << _GREYER << _ITALIC << "RobotomyRequestForm - Parametric constructor called" << _END << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {

	std::cout << _GREYER << _ITALIC << "RobotomyRequestForm - Destructor called" << _END << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm("Robotomy Request Form", 72, 45), _target(src.getTarget()){

	std::cout << _GREYER << _ITALIC << "RobotomyRequestForm - Copy constructor called" << _END << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const {

	return this->_target;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {

	(void)src;
	return *this;
}

void	RobotomyRequestForm::doAction(void) const {

	srand(time(NULL));
	static int rnd = rand();

	std::cout << _BROWN << "Bzzzz Bzzzz Bzzzz" << _BOLD << "Bzzzz" << _END << _BROWN << "BzzzzBzzzz " << _BOLD << "Bzzzz" << _END << _BROWN << "Bzzzz BzzzzBzzzz" << _END << std::endl;

	if (++rnd%2)
		std::cout << _YELLOW << this->_target << " has been robotomized " << _BOLD << "successfully" << _END << std::endl;
	else 
		std::cout << _YELLOW << this->_target << "'s' robotomy " << _BOLD << "failed" << _END << std::endl;
}
