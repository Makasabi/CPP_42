#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure"){

	std::cout << _ITALIC << _GREYER << "Cure - default constructor called" << _END << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type){

	std::cout << _ITALIC << _GREYER << "Cure - parametric constructor called" << _END << std::endl;
}

Cure::~Cure() {

	std::cout << _ITALIC << _GREYER << "Cure - destructor called" << _END << std::endl;
}

Cure::Cure(Cure const & src) : AMateria(src._type){

	std::cout << _ITALIC << _GREYER << "Cure - copy constructor called" << _END << std::endl;
	*this = src;
}

Cure & Cure::operator=(Cure const & src) {

	std::cout << _ITALIC << _GREYER << "Cure - copy operator called" << _END << std::endl;
	(void)src;
	this->_type = "cure";
	return *this;
}

std::string const & Cure::getType() const {
	return this->_type;
}

AMateria* Cure::clone(void) const {

	Cure *clone = new Cure("cure");
	return clone;
}

void Cure::use(ICharacter& target) {

	std::cout << _EMMERALD << "* heals " << target.getName() << "'s wounds *" << _END << std::endl;
}