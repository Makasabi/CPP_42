#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {

	std::cout << _PINK <<  "WrongCat Constructor Called" << _END << std::endl;
}

WrongCat::~WrongCat() { 

	std::cout << _PINK << "WrongCat Destructor Called" << _END << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal() {

	WrongAnimal::_type = type;
	std::cout << _PINK << "WrongCat Parametric Constructor Called" << _END << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal() { 

	std::cout << _PINK << "WrongCat Copy Constructor Called" << _END << std::endl;
	*this = src;
}

WrongCat & WrongCat::operator=(WrongCat const & src) { 

	_type = src.WrongAnimal::getType();
	return *this;
}

void	WrongCat::makeSound() {

	std::cout << _PINK << "Meow Meow" << _END << std::endl;
	return;
}