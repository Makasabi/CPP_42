#include "Dog.hpp"

Dog::Dog() : Animal() {

	std::cout << _FOREST_GREEN <<  "Dog Constructor Called" << _END << std::endl;
	Animal::_type = "Dog";
	_brain = new Brain();
}

Dog::~Dog() { 

	delete _brain;
	std::cout << _FOREST_GREEN << "Dog Destructor Called" << _END << std::endl;
}

Dog::Dog(Dog const & src) : Animal() { 

	std::cout << _FOREST_GREEN << "Dog Copy Constructor Called" << _END << std::endl;
	this->_type = src.Animal::getType();
	this->_brain = new Brain(*src.getBrain());
}

Dog & Dog::operator=(Dog const & src) { 

	this->_type = src.Animal::getType();
	delete this->_brain;
	this->_brain = new Brain(*src.getBrain());
	return *this;
}

Brain *Dog::getBrain(void) const {

	return _brain;
}

void	Dog::makeSound() {

	std::cout << _FOREST_GREEN << "Woof Woof" << _END << std::endl;
	return;
}