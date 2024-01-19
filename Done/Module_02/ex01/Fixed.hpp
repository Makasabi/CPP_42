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

private:

	int					_RawBits;
	static const int	_bits = 8;

};

std::ostream & operator << (std::ostream & o, Fixed const & rhs);


#endif