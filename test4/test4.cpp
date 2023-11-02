/*
Objects: class / constructors / destructors
Naming : Sample.class.hpp

*/

#include <iostream>
#include "test4.hpp"

test4::test4(void){

	std::cout << "Contructor called" << std::endl;
	return;
}

test4::~test4(void){

	std::cout << "Destructor called" << std::endl;
	return;
}

void	test4::bar(void) {

	std::cout << "Member function bar called" << std::endl;
	return ;
}
