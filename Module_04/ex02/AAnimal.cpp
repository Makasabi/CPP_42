#include "AAnimal.hpp"

AAnimal::AAnimal() {

	_type = "AAnimal";
	std::cout << _GREYER <<  "AAnimal Constructor Called" << _END << std::endl;
}

AAnimal::~AAnimal() { 

	std::cout << _GREYER << "AAnimal Destructor Called" << _END << std::endl;
}

AAnimal::AAnimal(AAnimal const & src) { 

	std::cout << _GREYER << "AAnimal Copy Constructor Called" << _END << std::endl;
	*this = src;
}

AAnimal & AAnimal::operator=(AAnimal const & src) { 

	_type = src.getType();
	return *this;
}

std::string AAnimal::getType() const {

	return _type;
}

// void	AAnimal::makeSound() {

// 	std::cout << "*not a single sound*" << std::endl;
// 	return;
// }