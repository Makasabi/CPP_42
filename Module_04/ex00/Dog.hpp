#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal {

	public:

	Dog();
	virtual ~Dog();
	Dog(Dog const & src);
	Dog & operator=(Dog const &);

	std::string getType(void) const;

	virtual void	makeSound();

};

#endif