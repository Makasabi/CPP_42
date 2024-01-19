#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"

class DiamondTrap :  public ScavTrap, public FragTrap {

public:

	DiamondTrap(void);
	~DiamondTrap(void);
	DiamondTrap(DiamondTrap const & src);
	DiamondTrap & operator=(DiamondTrap const & src);

	DiamondTrap( std::string const & name );

	void	whoAmI();
	void	attack( const std::string &  src);

private:

	std::string _name;
};

#endif