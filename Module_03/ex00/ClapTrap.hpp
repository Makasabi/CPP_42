#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class ClapTrap {

public:

	ClapTrap( void );
	ClapTrap(std::string const);
	ClapTrap(ClapTrap const &);
	~ClapTrap( void );

	ClapTrap & operator=(ClapTrap const &);

	std::string getName(void) const;
	int getHitPoint(void) const;
	int getEnergyPoint(void) const;
	int getAttackDamage(void) const;

	void setHitPoint(int n);
	void setEnergyPoint(int n);
	void setAttackDamage(int n);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	
private:

	std::string	_name;
	int			_hitPoint;
	int			_energyPoint;
	int			_attackDamage;
	
};

#endif