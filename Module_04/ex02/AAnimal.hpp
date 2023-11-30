#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class AAnimal {

public:
	AAnimal();
	virtual ~AAnimal();
	AAnimal(AAnimal const & src);
	AAnimal & operator=(AAnimal const &);

	std::string getType(void) const;

	virtual void	makeSound() = 0;

protected:
	std::string		_type;

};

#endif