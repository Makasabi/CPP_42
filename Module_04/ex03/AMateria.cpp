#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
}

AMateria::~AMateria() {
}

AMateria::AMateria(AMateria const & src) {

	*this = src;
}

AMateria & AMateria::operator=(AMateria const & src) {

	this->_type = src.getType();
	return *this;
}

std::string const & AMateria::getType() const { //Returns the materia type

	return this->_type;
}

AMateria* AMateria::clone() const {
	// return 
}

void AMateria::use(ICharacter& target) {

}