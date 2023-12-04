#include "Dog.hpp"

Dog::Dog() : AAnimal() {

	std::cout << _FOREST_GREEN <<  "Dog Constructor Called" << _END << std::endl;
	AAnimal::_type = "Dog";
	_brain = new Brain();
}

Dog::~Dog() { 

	delete _brain;
	std::cout << _FOREST_GREEN << "Dog Destructor Called" << _END << std::endl;
}

Dog::Dog(Dog const & src) : AAnimal() { 

	std::cout << _FOREST_GREEN << "Dog Copy Constructor Called" << _END << std::endl;
	*this = src;
}

Dog & Dog::operator=(Dog const & src) { 

	_type = src.AAnimal::getType();
	_brain = new Brain(*src.getBrain());
	return *this;
}

Brain *Dog::getBrain(void) const {

	return _brain;
}

void	Dog::makeSound() {

	std::cout << _FOREST_GREEN << "Woof Woof" << _END << std::endl;
	return;
}