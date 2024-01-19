#include "Fixed.hpp"


Fixed::Fixed( void ) : _RawBits( 0 ) {

	std::cout << _GREYER << "Default constructor called" << _END << std::endl;
	return;
}

Fixed::Fixed( Fixed const & src ) {

	std::cout << _FOREST_GREEN << "Copy constructor called" << _END << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed (void) {

	std::cout << _GREYER << "Destructor called" << _END << std::endl;
	return ;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {

	std::cout << _YELLOW << "Copy assignment operator called" << _END << std::endl;

	this->_RawBits = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const {

	std::cout <<  "getRawBits member function called" << std::endl;
	return this->_RawBits;
}

void	Fixed::setRawBits(int const raw) {

	std::cout << "setRawBits member function called" << std::endl;
	this->_RawBits = raw;
	return;
}