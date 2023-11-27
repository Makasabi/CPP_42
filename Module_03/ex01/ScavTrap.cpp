#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {

	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(20);
	std::cout << "ScavTrap - Default constructor called: " << _name << " is born. 🧌" << std::endl;
	return;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name){

	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(20);
	std::cout << "ScavTrap - Parametric constructor called: " << _name << " is born. 🧌" << std::endl;
	return ;
}


ScavTrap::ScavTrap( ScavTrap const & src) {

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
	
	if (getEnergyPoint() == 0) {
		std::cout << _MAGENTA << _name << " doesn't have enough energy for this !" << _END << std::endl;
		return;
	}
	std::cout << _SALMON << "\n🪓 " << _name << " has gone rogue and attacked " << target << ", causing [" << _attackDamage << "] points of damage! 🪓" << _END << std::endl;
	setEnergyPoint(getEnergyPoint() - 1);
	return ;
}

void ScavTrap::guardGate( void ) {

	std::cout << _KAKI << "\n🛡️  " << _name << " is now in guard mode..." << _END << std::endl;
	return ;
}