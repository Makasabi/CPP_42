#include "Sample.class.hpp"
#include <iostream>

Sample::Sample() {

	std::cout << "Constructor called" << std::endl;
	Sample::_nbInst += 1;
	return;
}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	Sample::_nbInst -= 1;
	return;
}

int	Sample::getNbInst( void )  {

	return Sample::_nbInst;
}

int	Sample::_nbInst = 0;