/*
Objects: class / constructors / destructors
Naming : Sample.class.hpp
*/

#include <iostream>
#include <string>
#include "test5.hpp"

test5::test5(void){

	std::cout << "Contructor called" << std::endl;

	this->foo = 42;
	this->color = "red";
	std::cout << "this->foo = [" << this->foo << "]" << std::endl;

	this->bar();
	return;
}

void	test5::paint(std::string color)
{
	this->color = color;
}

test5::~test5(void){

	std::cout << "Destructor called" << std::endl;
	return;
}

void	test5::bar(void) {

	std::cout << "Member function bar called" << std::endl;
	return ;
}
