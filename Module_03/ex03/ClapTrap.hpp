#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class ClapTrap {

public:

	ClapTrap(void);
	ClapTrap(std::string const);
	ClapTrap(ClapTrap const &);
	~ClapTrap(void);

	ClapTrap & operator=(ClapTrap const &);

	std::string getName(void) const;
	unsigned int getHitPoint(void) const;
	unsigned int getEnergyPoint(void) const;
	unsigned int getAttackDamage(void) const;

	void attack(const std::string & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	
protected:

	std::string	_name;
	unsigned int	_hitPoint;
	unsigned int	_energyPoint;
	unsigned int	_attackDamage;
	
};

#endif