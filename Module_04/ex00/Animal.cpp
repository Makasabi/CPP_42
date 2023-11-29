#include "Animal.hpp"

Animal::Animal() {

	std::cout << _GREYER <<  "Animal Constructor Called" << _END << std::endl;
}

Animal::~Animal() { 

	std::cout << _GREYER << "Animal Destructor Called" << _END << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	
	std::cout << _GREYER << "Animal Parametric Constructor Called" << _END << std::endl;
}

Animal::Animal(Animal const & src) { 

	std::cout << _GREYER << "Animal Copy Constructor Called" << _END << std::endl;
	*this = src;
}

Animal & Animal::operator=(Animal const & src) { 

	_type = src.getType();
	return *this;
}

std::string Animal::getType() const {

	return _type;
}

void	Animal::makeSound() {

	return;
}