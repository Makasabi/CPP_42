#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {

public:

	Cure(void);
	Cure(std::string const & type);
	~Cure();
	Cure(Cure const & src);

	Cure & operator=(Cure const & src);

	std::string const & getType() const;

	virtual AMateria* clone(void) const;
	virtual void use(ICharacter& target);

};

#endif