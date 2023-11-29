#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal {

	public:
		Animal();
		~Animal();
		Animal(Animal const & src);
		Animal & operator=(Animal const &);

		virtual void	makeSound() = 0;

	protected:
		std::string		type;
};

#endif