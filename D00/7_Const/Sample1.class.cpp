#include <iostream>
#include "Sample1.class.hpp"

Sample1::Sample1(float const f) : pi(f), qd(42) {

	std::cout << "Constructor Called" << std::endl;
	return ;
}

Sample1::~Sample1( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample1::bar( void ) const {

	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "this->qd = " << this->qd << std::endl;

	// this->qd = 0; // Impossible car on ne peut pas modifier l'instance courant dans une fonction membre constante.
}
/* Cette fonction membre ne modifiera jamais l'instance courante.*/