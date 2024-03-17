
#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){

	std::cout << _ITALIC << _GREYER << "Ice - default constructor called" << _END << std::endl;
}


Ice::Ice(std::string const & type) : AMateria(type){

	std::cout << _ITALIC << _GREYER << "Ice - parametric constructor called" << _END << std::endl;
}

Ice::~Ice() {
	std::cout << _ITALIC << _GREYER << "Ice - destructor called" << _END << std::endl;
}

Ice::Ice(Ice const & src) : AMateria(src._type){

	std::cout << _ITALIC << _GREYER << "Ice - copy constructor called" << _END << std::endl;
	*this = src;
}

Ice & Ice::operator=(Ice const & src) {

	std::cout << _ITALIC << _GREYER << "Ice - copy operator called" << _END << std::endl;
	(void)src;
	this->_type = "ice";
	return *this;
}

std::string const & Ice::getType() const {
	return this->_type;
}

AMateria* Ice::clone(void) const {

	Ice *clone = new Ice("ice");
	return clone;
}

void Ice::use(ICharacter& target) {

	std::cout << _AQUAMARINE << "* shoots an ice bolt at " << target.getName() << " *" << _END << std::endl;
}