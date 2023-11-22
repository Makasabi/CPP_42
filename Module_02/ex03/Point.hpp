#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

public:

	Point( void );
	Point( float const x, float const y );
	Point( Fixed const x, Fixed const y );
	Point( Point const & src );
	~Point( void );

	Point &	operator=( Point & rhs );

	Fixed const getX() const;
	Fixed const getY() const;

private:

	Fixed const _x;
	Fixed const _y;
};

#endif