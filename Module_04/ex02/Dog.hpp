#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal {

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