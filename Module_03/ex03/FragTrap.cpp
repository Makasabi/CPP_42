#include "FragTrap.hpp"
#include <cstring>

FragTrap::FragTrap( void ) : ClapTrap() {

	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << _CYAN << "FragTrap - Default constructor called: " << _name << " is born 🧝" << _END << std::endl;
	return;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name){

	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << _CYAN << "FragTrap - Parametric constructor called: " << _name << " is born 🧝" << _END << std::endl;
	return ;
}


FragTrap::FragTrap( FragTrap const & src) {

	std::cout << _CYAN << "FragTrap - Copy constructor called: " << _name << " is born 🧝" << _END << std::endl;
	*this = src;
	return;
}

FragTrap::~FragTrap( void ) {

	std::cout << _CYAN << "FragTrap - Destructor called: " << _name << " has left middle hearth 🧝" << _END << std::endl;
	return;
}

FragTrap & FragTrap::operator=(FragTrap const & src) {

	_name = src.getName();
	_hitPoint = src.getHitPoint();
	_energyPoint = src.getEnergyPoint();
	_attackDamage = src.getAttackDamage();
	return *this;
}

void FragTrap::highFivesGuys( void ) {

	std::string buff;
	std::cout << _LAGOON << "🗡️ " << _name << " is making a battle speech to rally forces " << std::endl;
	std::cout << _GREYER <<  "Show your support for frodo..." << _END << std::endl;
	std::getline(std::cin, buff);
	if (std::cin.eof() || std::strcmp("FOR FRODO!", buff.c_str()) != 0) {
		std::cout << "You should have screamed : 'FOR FRODO!'" <<std::endl;
		return ;
	}
	std::cout << _BOLD << "Yiiihhhaaaaaaaaaa!" << _END <<std::endl;
	return;
}


	