#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap() {

	this->_name = "Someone great";
	ClapTrap::_name = _name + "_clap_name";
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << _LAGOON << "DiamondTrap - Default constructor called: " << _name << " is born 🧙" << _END << std::endl;
	return;
}

DiamondTrap::DiamondTrap( std::string const & name ) : ClapTrap(), ScavTrap(), FragTrap(), _name(name) {

	ClapTrap::_name = _name + "_clap_name";
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << _LAGOON << "DiamondTrap - Parametric constructor called: " << _name << " is born 🧙" << _END << std::endl;
	return ;
}


DiamondTrap::DiamondTrap( DiamondTrap const & src) : ClapTrap(), ScavTrap(), FragTrap() {

	std::cout << _LAGOON << "DiamondTrap - Copy constructor called: " << _name << " is born 🧙" << _END << std::endl;
	*this = src;
	return;
}

DiamondTrap::~DiamondTrap( void ) {

	std::cout << _LAGOON << "DiamondTrap - Destructor called: " << _name << " has returned to the Shire 🏞️" << _END << std::endl;
	return;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & src) {

	_name = src.getName();
	_hitPoint = src.getHitPoint();
	_energyPoint = src.getEnergyPoint();
	_attackDamage = src.getAttackDamage();
	return *this;
}

void	DiamondTrap::attack( const std::string &  src) {
	ScavTrap::attack(src);
}

void	DiamondTrap::whoAmI() {

	std::cout << _BOLD << "I am " << _name << " also known as " << ClapTrap::_name << _END << std::endl;

	std::cout << "here are my specs :" << std::endl;
	std::cout << "Hit Points :\t" << _hitPoint << std::endl;
	std::cout << "EnergyPoint :\t" << _energyPoint << std::endl;
	std::cout << "Attack Damage :\t" << _attackDamage << std::endl;

	// std::cout << "\nI inherited from ClapTrap, " << std::endl;
	// std::cout << "Name :\t\t" << ClapTrap::_name << std::endl;
	// std::cout << "Hit Points :\t" << ClapTrap::_hitPoint << std::endl;
	// std::cout << "EnergyPoint :\t" << ClapTrap::_energyPoint << std::endl;
	// std::cout << "Attack Damage :\t" << ClapTrap::_attackDamage << std::endl;

	// std::cout << "\nfrom ScavTrap," << std::endl;
	// std::cout << "Name :\t\t" << ScavTrap::_name << std::endl;
	// std::cout << "Hit Points :\t" << ScavTrap::_hitPoint << std::endl;
	// std::cout << "EnergyPoint :\t" << ScavTrap::_energyPoint << std::endl;
	// std::cout << "Attack Damage :\t" << ScavTrap::_attackDamage << std::endl;

	// std::cout << "\nand from FragTrap" << std::endl;
	// std::cout << "Name :\t\t" << FragTrap::_name << std::endl;
	// std::cout << "Hit Points :\t" << FragTrap::_hitPoint << std::endl;
	// std::cout << "EnergyPoint :\t" << FragTrap::_energyPoint << std::endl;
	// std::cout << "Attack Damage :\t" << FragTrap::_attackDamage << std::endl;

	return ;
}