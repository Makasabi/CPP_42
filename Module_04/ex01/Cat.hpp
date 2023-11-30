#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {

public:

	Cat();
	virtual ~Cat();
	Cat(Cat const & src);
	Cat & operator=(Cat const &);

	std::string getType(void) const;
	Brain *getBrain(void) const;

	virtual void	makeSound();

private:

	Brain *_brain;
};

#endif