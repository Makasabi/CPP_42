#include "Cat.hpp"

Cat::Cat() : Animal() {

	std::cout << _PINK <<  "Cat Constructor Called" << _END << std::endl;
	Animal::_type = "Cat";
	_brain = new Brain();
}

Cat::~Cat() { 

	delete _brain;
	std::cout << _PINK << "Cat Destructor Called" << _END << std::endl;
}

Cat::Cat(Cat const & src) : Animal() { 

	std::cout << _PINK << "Cat Copy Constructor Called" << _END << std::endl;
	this->_type = src.Animal::getType();
	this->_brain = new Brain(*src.getBrain());
}

Cat & Cat::operator=(Cat const & src) { 

	this->_type = src.Animal::getType();
	delete this->_brain;
	this->_brain = new Brain(*src.getBrain());
	return *this;
}

Brain *Cat::getBrain(void) const {

	return _brain;
}

void	Cat::makeSound() {

	std::cout << _PINK << "Meow Meow" << _END << std::endl;
	return;
}