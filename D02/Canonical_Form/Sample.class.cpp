#include "Sample.class.hpp"

Sample::Sample (void) : _foo( 21 ) {

	std::cout << "Default Constructor called" << std::endl;

	return ;
}

Sample::Sample (int const n) : _foo(n) {

	std::cout << "Parametric  Constructor called" << std::endl;

	return ;
}

Sample::Sample( Sample const & src ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return;
}

Sample::~Sample (void) {

	std::cout << "Destructor called" << std::endl;

	return ;
}

Sample &	Sample::operator=( Sample const & rhs ) {

	std::cout << "Assignation operator called from " << this->_foo;
	std::cout << " to " << rhs.getfoo() << std::endl;

	this->_foo = rhs.getfoo();
	return *this;
}


int Sample::getfoo( void ) const {

	return this->_foo;
}

std::ostream & operator << (std::ostream & a, Sample const & rhs){

	a << rhs.getfoo();
	return a;
}
