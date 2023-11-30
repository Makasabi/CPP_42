#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class Animal {

public:
	Animal();
	virtual ~Animal();
	Animal(Animal const & src);
	Animal & operator=(Animal const &);

	std::string getType(void) const;

	virtual void	makeSound();

protected:
	std::string		_type;

};

#endif