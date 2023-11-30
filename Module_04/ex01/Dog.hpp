#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {

public:

	Dog();
	virtual ~Dog();
	Dog(Dog const & src);
	Dog & operator=(Dog const &);

	std::string getType(void) const;
	Brain *getBrain(void) const;

	virtual void	makeSound();

private:

	Brain *_brain;
};

#endif