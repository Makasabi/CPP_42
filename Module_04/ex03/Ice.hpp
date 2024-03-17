#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria {

public:

	Ice(void);
	Ice(std::string const & type);
	~Ice();
	Ice(Ice const & src);

	Ice & operator=(Ice const & src);

	std::string const & getType() const;

	virtual AMateria* clone(void) const;
	virtual void use(ICharacter& target);

};

#endif