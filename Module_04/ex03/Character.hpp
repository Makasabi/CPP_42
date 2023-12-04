#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {

	public:
		Character(void);
		Character(std::string name);
		virtual ~Character();
		Character(Character const & src);

		Character & operator=(Character const & src);

		virtual std::string const & getName() const;
		virtual AMateria const * getMateria(int idx) const;

		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	private:

		std::string	_name;
		AMateria	*_materias[4];
};

#endif