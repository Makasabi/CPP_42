#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {

	public:

	WrongCat();
	~WrongCat();
	WrongCat(std::string name);
	WrongCat(WrongCat const & src);
	WrongCat & operator=(WrongCat const &);

	std::string getType(void) const;

	void	makeSound();

	protected:

};

#endif