#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {

public:

	ScavTrap( void );
	~ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( ScavTrap const & src);
	ScavTrap & operator=( ScavTrap const & );

	void attack( const std::string& target );
	void guardGate();

protected:
	int			_energyPoint;
};

#endif