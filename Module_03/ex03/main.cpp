#include "colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {

	// ClapTrap Hobbit("Bilbo Baggins");
	// ScavTrap Orc( "Azog" );
	// FragTrap Elf( "Legolas" );
	DiamondTrap Gandalf("Gandalf");

	Gandalf.whoAmI();

	return 0;
}