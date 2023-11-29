#include "colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

	ClapTrap Hobbit("Bilbo Baggins");
	ScavTrap Orc("Azog");

	Hobbit.attack(Orc.getName());

	Orc.guardGate();

	Hobbit.attack(Orc.getName());

	Hobbit.beRepaired(20);

	Orc.attack(Hobbit.getName());
	Hobbit.takeDamage(Orc.getAttackDamage());

	Orc.attack(Hobbit.getName());
	Hobbit.takeDamage(Orc.getAttackDamage());

	return 0;
}