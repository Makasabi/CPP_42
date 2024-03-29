#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal {

	public:

	Cat();
	virtual ~Cat();
	Cat(Cat const & src);
	Cat & operator=(Cat const &);

	std::string getType(void) const;

	virtual void	makeSound();

};

#endif