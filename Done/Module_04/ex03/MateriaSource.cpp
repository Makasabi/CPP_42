#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {

	std::cout << _ITALIC << _GREYER << "MateriaSource - default constructor called" << _END << std::endl;
	for (std::size_t i = 0; i < 4; i++)
		this->_knowledge[i] = NULL;
}

MateriaSource::~MateriaSource() {

	std::cout << _ITALIC << _GREYER << "MateriaSource - destructor called" << _END << std::endl;
	for (std::size_t i = 0; i < 4; i++) {
		if (_knowledge[i] != NULL)
			delete this->_knowledge[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const & src) : IMateriaSource() {

	std::cout << _ITALIC << _GREYER << "MateriaSource - copy constructor called" << _END << std::endl;
	for (std::size_t i = 0; i < 4; i++) {
		if (this->_knowledge[i] != NULL) {
			delete this->_knowledge[i];
			this->_knowledge[i] = NULL;
		}
	}
	*this = src;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & src) {

	std::cout << _ITALIC << _GREYER << "MateriaSource - copy operator called" << _END << std::endl;
	for (std::size_t i = 0; i < 4; i++) {
		if (src._knowledge[i] != NULL)
			this->_knowledge[i] = src._knowledge[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* power){
	
	if (!power)
		return;
	for (std::size_t i = 0; i < 4; i++)
		if (_knowledge[i] != NULL 
		&& this->_knowledge[i]->getType() == power->getType())
			return;
	for (std::size_t i = 0; i < 4; i++) {
		if (this->_knowledge[i] == NULL) {
			this->_knowledge[i] = power;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type){

	for (std::size_t i = 0; i < 4; i++) {
		if (_knowledge[i] != NULL 
		&& this->_knowledge[i]->getType() == type)
		{
			return this->_knowledge[i]->clone();
		}
	}
	return NULL;
}