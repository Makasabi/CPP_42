#include "colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {

	DiamondTrap Gandalf("Gandalf");

	Gandalf.whoAmI();
	Gandalf.attack("Saruman");
	Gandalf.beRepaired(10);
	Gandalf.highFivesGuys();
	Gandalf.guardGate();

	return 0;
}