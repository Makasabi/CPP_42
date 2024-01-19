#include <iostream>
#include "Integer.class.hpp"

Integer::Integer(int const n) : _n( n ) {

	std::cout << "Constructor called with value " << n << std::endl;
}

Integer::~Integer( void ) {

	std::cout << "Destructor called" << std::endl;
}

int		Integer::getvalue( void )const {

	return this->_n;
}

Integer &	Integer::operator=( Integer const & rhs ) {

	std::cout << "Assignation operator called from " << this->_n;
	std::cout << " to " << rhs.getvalue() << std::endl;

	this->_n = rhs.getvalue();
	return *this;
}

Integer		Integer::operator+( Integer const & rhs ) const {

	std::cout << "Assignation operator called with " << this->_n;
	std::cout << " and " << rhs.getvalue() << std::endl;

	return Integer (this->_n + rhs.getvalue() );
}

std::ostream & operator << (std::ostream & a, Integer const & rhs){

	a << rhs.getvalue();
	return a;
}
