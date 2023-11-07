#include <iostream>
#include "Sample2.class.hpp"

Sample2::Sample2( void ) {

	std::cout << "Constructor Called" << std::endl;
	return ;
}

Sample2::~Sample2( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample2::bar( void ) const {

	std::cout << "Member function Bar called" << std::endl;

}
