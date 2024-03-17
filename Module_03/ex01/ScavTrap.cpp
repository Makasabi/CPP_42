#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {

	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap - Default constructor called: " << _name << " is born. 🧌" << std::endl;
	return;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name){

	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap - Parametric constructor called: " << _name << " is born. 🧌" << std::endl;
	return;
}


ScavTrap::ScavTrap( ScavTrap const & src) : ClapTrap() {

	std::cout << "ScavTrap - Copy constructor called: " << _name << " is born. 🧌" << _END << std::endl;
	*this = src;
	return;
}

ScavTrap::~ScavTrap( void ) {

	std::cout << "ScavTrap - Destructor called: " << _name << " is gone 🧌" << std::endl;
	return;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src) {

	_name = src.getName();
	_hitPoint = src.getHitPoint();
	_energyPoint = src.getEnergyPoint();
	_attackDamage = src.getAttackDamage();
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	
	if (_energyPoint <= 0 || _hitPoint <= 0) {
		std::cout << _MAGENTA << _name << " doesn't have enough energy or hit points for this !" << _END << std::endl;
		return;
	}
	std::cout << _SALMON << "\n🪓 " << _name << " has gone rogue and attacked " << target << ", causing [" << _attackDamage << "] points of damage! 🪓" << _END << std::endl;
	_energyPoint = _energyPoint - 1;
	std::cout << "\t🍃 " << _name << "'s remaining energy points:\t[" << _energyPoint << "]" << std::endl;
	return ;
}	

void ScavTrap::guardGate( void ) {

	if (_energyPoint <= 0 || _hitPoint <= 0) {
		std::cout << _MAGENTA << _name << " doesn't have enough energy or hit points for this !" << _END << std::endl;
		return;
	}
	std::cout << _KAKI << "\n🛡️  " << _name << " is now in guard mode..." << _END << std::endl;
	return ;
}