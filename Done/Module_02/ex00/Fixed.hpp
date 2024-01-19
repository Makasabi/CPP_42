#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include "colors.hpp"

class Fixed {

public:

	Fixed	( void );
	Fixed	(Fixed const & src);
	~Fixed	( void );

	Fixed &	operator=( Fixed const & rhs );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw);

private:

	int					_RawBits;
	static const int	_bits = 8;

};

#endif