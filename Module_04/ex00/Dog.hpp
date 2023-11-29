#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal {

	public:

	Dog();
	virtual ~Dog();
	Dog(std::string name);
	Dog(Dog const & src);
	Dog & operator=(Dog const &);

	std::string getType(void) const;

	virtual void	makeSound();

	protected:

};

#endif