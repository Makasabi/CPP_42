#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class WrongAnimal {

public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(std::string name);
	WrongAnimal(WrongAnimal const & src);
	WrongAnimal & operator=(WrongAnimal const &);

	std::string getType(void) const;

	void	makeSound();

protected:
	std::string		_type;

};

#endif