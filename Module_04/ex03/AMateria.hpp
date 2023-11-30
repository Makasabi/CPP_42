#ifndef MATERIA_HPP
# define MATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria
{

	public:

		AMateria(std::string const & type);
		~AMateria();
		AMateria(AMateria const & src);

		AMateria & operator=(AMateria const & src);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
	
		std::string	_type;
};

#endif