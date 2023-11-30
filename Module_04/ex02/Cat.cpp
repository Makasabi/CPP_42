#include "Cat.hpp"

Cat::Cat() : AAnimal() {

	std::cout << _PINK <<  "Cat Constructor Called" << _END << std::endl;
	AAnimal::_type = "Cat";
	_brain = new Brain();
}

Cat::~Cat() { 

	delete _brain;
	std::cout << _PINK << "Cat Destructor Called" << _END << std::endl;
}

Cat::Cat(Cat const & src) : AAnimal() { 

	std::cout << _PINK << "Cat Copy Constructor Called" << _END << std::endl;
	*this = src;
}

Cat & Cat::operator=(Cat const & src) { 

	_type = src.AAnimal::getType();
	_brain = new Brain(*src.getBrain());
	return *this;
}

Brain *Cat::getBrain(void) const {

	return _brain;
}

void	Cat::makeSound() {

	std::cout << _PINK << "Meow Meow" << _END << std::endl;
	return;
}