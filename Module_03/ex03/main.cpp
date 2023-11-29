#include "colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {

	DiamondTrap Gandalf("Gandalf");

	Gandalf.whoAmI();
	Gandalf.attack("Saruman");
	std::cout << std::endl;
	Gandalf.beRepaired(10);
	std::cout << std::endl;
	Gandalf.highFivesGuys();
	std::cout << std::endl;
	Gandalf.guardGate();
	std::cout << std::endl;

	return 0;
}