#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character(void) : ICharacter() {

	std::cout << _ITALIC << _GREYER << "Character - default constructor called" << _END << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

Character::Character(std::string name) : ICharacter(), _name(name) {

	std::cout << _ITALIC << _GREYER << "Character - parametric constructor called" << _END << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

Character::~Character() {

	std::cout << _ITALIC << _GREYER << "Character - destructor called" << _END << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_materias[i] != NULL)
			delete this->_materias[i];
	}
}

Character::Character(Character const & src) : ICharacter() {

	std::cout << _ITALIC << _GREYER << "Character - copy constructor called" << _END << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] != NULL) {
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
	*this = src;
}

Character & Character::operator=(Character const & src){

	std::cout << _ITALIC << _GREYER << "Character - copy operator called" << _END << std::endl;
	for (int i = 0; i < 4; i++) {
		if (src._materias[i] != NULL)
			this->_materias[i] = src._materias[i]->clone();
	}
	this->_name = src.getName();
	return *this;
}

std::string const & Character::getName() const {

	return this->_name;
}

AMateria const * Character::getMateria(int idx) const {

	if (idx < 0 || idx > 4)
		return 0;
	return this->_materias[idx];
}


void Character::equip(AMateria* m){

	if (m == 0)
		return;
	for (int i = 0; i < 4; i++){
		if (this->_materias[i] == NULL) {
			this->_materias[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx){

	if (idx < 0 || idx > 4)
		return;
	if (_materias[idx] != NULL)
		_materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){

	if (idx < 0 || idx > 4)
		return;
	if (_materias[idx] != NULL)
		_materias[idx]->use(target);
}