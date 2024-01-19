#include <iostream>
#include "Sample1.class.hpp"

Sample1::Sample1( void ) {

	std::cout << "Constructor Called" << std::endl;
	return ;
}

Sample1::~Sample1( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

int	Sample1::getFoo(void) const {

	return this->_Foo;
}

void	Sample1::setFoo(int v) {

	if (v >= 0)
		this->_Foo = v;
	return;
}