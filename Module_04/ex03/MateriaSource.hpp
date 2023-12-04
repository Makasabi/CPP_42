#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <cstring>

class MateriaSource : public IMateriaSource {

public : 

	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource(MateriaSource const & src);

	MateriaSource & operator=(MateriaSource const & src);

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);

private :
	AMateria	*_knowledge[4];

};

#endif