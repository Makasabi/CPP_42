#include "Cat.hpp"

Cat::Cat() : Animal() {

	std::cout << _PINK <<  "Cat Constructor Called" << _END << std::endl;
}

Cat::~Cat() { 

	std::cout << _PINK << "Cat Destructor Called" << _END << std::endl;
}

Cat::Cat(std::string type) : Animal() {

	Animal::_type = type;
	std::cout << _PINK << "Cat Parametric Constructor Called" << _END << std::endl;
}

Cat::Cat(Cat const & src) : Animal() { 

	std::cout << _PINK << "Cat Copy Constructor Called" << _END << std::endl;
	*this = src;
}

Cat & Cat::operator=(Cat const & src) { 

	_type = src.Animal::getType();
	return *this;
}

void	Cat::makeSound() {

	std::cout << _PINK << "Meow Meow" << _END << std::endl;
	return;
}