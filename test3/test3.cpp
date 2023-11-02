/*
Objects: class / constructors / destructors
Naming : Sample.class.hpp

*/

#include <iostream>
#include "test3.hpp"

test3::test3(void){

	std::cout << "Contructor called" << std::endl;
	return;
}

test3::~test3(void){

	std::cout << "Destructor called" << std::endl;
	return;
}

