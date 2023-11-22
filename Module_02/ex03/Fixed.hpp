#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <cmath>
# include "colors.hpp"

# define TOO_BIG "is too big to fit in fixed point - Rawbit set at 0"

class Fixed {

public:

	Fixed	( void );
	Fixed	(Fixed const & src);
	Fixed	(const int n );
	Fixed	(const float m );
	~Fixed	( void );

	Fixed &	operator=( Fixed const & rhs );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw);

	float	toFloat( void ) const;
	int		toInt( void ) const;

	/* comparison operators */
	bool operator<(Fixed const & rhs) const;
	bool operator>(Fixed const & rhs) const;
	bool operator<=(Fixed const & rhs) const;
	bool operator>=(Fixed const & rhs) const;
	bool operator==(Fixed const & rhs) const;
	bool operator!=(Fixed const & rhs) const;

	/* Arithmetic operators */
	Fixed operator+(Fixed const & rhs) const;
	Fixed operator-(Fixed const & rhs) const;
	Fixed operator*(Fixed const & rhs) const;
	Fixed operator/(Fixed const & rhs) const;

	/* pre incrementation operators */
	Fixed & operator++();
	Fixed & operator--();

	/* post incrementation operators */
	Fixed operator++(int);
	Fixed operator--(int);

	/* Overloaded functions */
	static Fixed min(Fixed & a, Fixed & b);
	static Fixed min(Fixed const & a, Fixed const & b );

	static Fixed max(Fixed & a, Fixed & b);
	static Fixed max(Fixed const & a, Fixed const & b );

private:

	int					_RawBits;
	static const int	_bits = 8;

};

std::ostream & operator << (std::ostream & o, Fixed const & rhs);


#endif