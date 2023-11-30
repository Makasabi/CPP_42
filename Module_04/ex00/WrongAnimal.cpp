#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {

	_type = "WrongAnimal";
	std::cout << _GREYER <<  "WrongAnimal Constructor Called" << _END << std::endl;
}

WrongAnimal::~WrongAnimal() { 

	std::cout << _GREYER << "WrongAnimal Destructor Called" << _END << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	
	std::cout << _GREYER << "WrongAnimal Parametric Constructor Called" << _END << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) { 

	std::cout << _GREYER << "WrongAnimal Copy Constructor Called" << _END << std::endl;
	*this = src;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & src) { 

	_type = src.getType();
	return *this;
}

std::string WrongAnimal::getType() const {

	return _type;
}

void	WrongAnimal::makeSound() {

	std::cout << "*not a single sound*" << std::endl;
	return;
}