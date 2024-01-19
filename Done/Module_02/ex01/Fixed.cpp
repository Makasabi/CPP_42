#include "Fixed.hpp"

/********************************************/
/*		CONSTRUCTORS - DESTRUCTOR			*/
/********************************************/

/* Default constructor - sets _rawbit to 0*/

Fixed::Fixed( void ) : _RawBits( 0 ) {

	std::cout << _GREYER << "Default constructor called" << _END << std::endl;
	return;
}

/* Copy constructor - returns a pointer to the copy of the instance passed as arg */

Fixed::Fixed( Fixed const & src ) {

	std::cout << _FOREST_GREEN << "Copy constructor called" << _END << std::endl;
	*this = src;
	return;
}

/* Constructor using an int - the int is bit-shifted by _bits to the left. 
Security check implemented to protect int that don't fit in 24bits*/

Fixed::Fixed(const int n ) {

	std::cout << _PURPLE << "Int constructor called" << _END << std::endl;
	if (n > (1 << 23) || n < -(1 << 23) -1 ) {
		std::cout << "Int" << TOO_BIG << std::endl;
		this->_RawBits = 0;
		return;
	}
	this->_RawBits = n << this->_bits;
	return;
}


/* Constructor using a float - the float is bit-shifted by _bits to the left. 
Security check implemented to protect floats that don't fit in 24bits*/

Fixed::Fixed(const float f ) {

	std::cout << _RED << "Float constructor called" << _END << std::endl;
	if (f > (1 << 23) || f < (-(1 << 23) -1) ) {
		std::cout << "FLoat " << TOO_BIG << std::endl;
		this->_RawBits = 0;
		return;
	}
	this->_RawBits = roundf(f * (1 << this->_bits));
	return;
}

Fixed::~Fixed (void) {

	std::cout << _GREYER << "Destructor called" << _END << std::endl;
	return ;
}

/********************************************/
//				OPERATOR OVERLOAD			//
/********************************************/


/* This one allows for the copy constructor build a new instance of the class "Fixed" with the same value of _RawBits*/
Fixed &	Fixed::operator=( Fixed const & rhs ) {

	std::cout << _YELLOW << "Copy assignment operator called" << _END << std::endl;

	this->_RawBits = rhs.getRawBits();
	return *this;
}

/********************************************/
//				OSTREAM OVERLOAD			//
/********************************************/

std::ostream & operator<<(std::ostream & a, Fixed const & rhs){

	a << rhs.toFloat();
	return a;
}


/********************************************/
//				MEMBER FUNCTIONS			//
/********************************************/

/* getter of private attribute _Rawbits*/
int		Fixed::getRawBits( void ) const {

	return this->_RawBits;
}

/*setter of private attribute _Rawbits*/
void	Fixed::setRawBits(int const raw) {

	this->_RawBits = raw;
	return;
}

/* Memeber fuunction that experesses the fixed point in float*/
float	Fixed::toFloat( void ) const {

	float	res = (static_cast<float>(this->getRawBits()) / (1 << this->_bits));
	return (res);
}

/* Memeber fuunction that experesses the fixed point in int*/
int		Fixed::toInt( void ) const {

	return (this->getRawBits() >> this->_bits);
}