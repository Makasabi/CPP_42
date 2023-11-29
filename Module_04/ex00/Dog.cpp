#include "Dog.hpp"

Dog::Dog() : Animal() {

	std::cout << _FOREST_GREEN <<  "Dog Constructor Called" << _END << std::endl;
}

Dog::~Dog() { 

	std::cout << _FOREST_GREEN << "Dog Destructor Called" << _END << std::endl;
}

Dog::Dog(std::string type) : Animal() {

	Animal::_type = type;
	std::cout << _FOREST_GREEN << "Dog Parametric Constructor Called" << _END << std::endl;
}

Dog::Dog(Dog const & src) : Animal() { 

	std::cout << _FOREST_GREEN << "Dog Copy Constructor Called" << _END << std::endl;
	*this = src;
}

Dog & Dog::operator=(Dog const & src) { 

	_type = src.Animal::getType();
	return *this;
}

void	Dog::makeSound() {

	std::cout << _FOREST_GREEN << "Woof Woof" << _END << std::endl;
	return;
}