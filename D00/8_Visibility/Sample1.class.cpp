#include <iostream>
#include "Sample1.class.hpp"

Sample1::Sample1( void ) {

	std::cout << "Constructor Called" << std::endl;

	this->publicFoo = 0;
	std::cout << "This->publicFoo: " << this->publicFoo << std::endl;
	this->_privateFoo = 0;
	std::cout << "This->privateFoo: " << this->_privateFoo << std::endl;

	this->publicBar();
	this->_privateBar();
	return ;
}

Sample1::~Sample1( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample1::publicBar( void ) const {

	std::cout << "Member function publicBar called" << std::endl;

}

void	Sample1::_privateBar( void ) const {

	std::cout << "Member function _privateBar called" << std::endl;

}

