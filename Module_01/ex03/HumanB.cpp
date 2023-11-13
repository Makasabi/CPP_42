#include <string>
#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"
#include "colors.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {

	std::cout << _FOREST_GREEN << _name << " constructed" << _END << std::endl;
}

HumanB::~HumanB() {
	std::cout << _ORANGE << _name << " destructed" << _END << std::endl;
}

void	HumanB::attack( void ) {

	std::cout << _name << " attacks with their " << (this->_weapon == NULL? "rock solid head": _weapon->getType()) << std::endl;
}

void	HumanB::setWeapon(Weapon* weaponREF) {

	_weapon = weaponREF;
}