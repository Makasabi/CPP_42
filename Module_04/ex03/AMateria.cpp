# include "AMateria.hpp"

AMateria::AMateria(void) {

	std::cout << _ITALIC << _GREYER << "AMateria - default constructor called" << _END << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {

	std::cout << _ITALIC << _GREYER << "AMateria - parametric constructor called" << _END << std::endl;
}

AMateria::~AMateria() {

	std::cout << _ITALIC << _GREYER << "AMateria - destructor called" << _END << std::endl;
}

AMateria::AMateria(AMateria const & src) {

	std::cout << _ITALIC << _GREYER << "AMateria - copy constructor called" << _END << std::endl;
	*this = src;
}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {

	(void)target;
	return;
}