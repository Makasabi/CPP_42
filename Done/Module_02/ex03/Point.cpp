#include "Point.hpp"
#include "Fixed.hpp"

Point::Point ( void ) : _x( 0 ), _y( 0 ) {

	// std::cout << "Default constructor called" << std::endl;
	return;
}

Point::Point ( float x, float y ) : _x( x ), _y( y ) {

	// std::cout << "Float constructor called" << std::endl;
	return;
}

Point::Point ( Fixed x, Fixed y ) : _x( x ), _y( y ) {

	// std::cout << "Fixed constructor called" << std::endl;
	return;
}


Point::Point( Point const & src) : _x(src.getX()), _y(src.getY()) {

	return;
}

Point::~Point( void ){
	
	return;
}

Point &	Point::operator=( Point & rhs ) {

	Point & tmp = rhs;
	return tmp;
}

Fixed const Point::getX() const {

	return this->_x;
}

Fixed const Point::getY() const{

	return this->_y;
}
