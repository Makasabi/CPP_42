#include <string>
#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"
#include "colors.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {

	std::cout << _FOREST_GREEN << _name << " constructed" << _END << std::endl;
}

HumanA::~HumanA() {

	std::cout << _ORANGE << _name << " destructed" << _END << std::endl;
}

void	HumanA::attack( void ) {

	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;

}