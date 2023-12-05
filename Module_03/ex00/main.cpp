#include "colors.hpp"
#include "ClapTrap.hpp"

int main(void) {

	ClapTrap Hobbit("Bilbo Baggins");

	Hobbit.attack("Azog");
	Hobbit.takeDamage(10);
	Hobbit.attack("Azog");
	Hobbit.beRepaired(4);
	Hobbit.attack("Azog");
	Hobbit.attack("Azog");
	Hobbit.takeDamage(6);
	Hobbit.attack("Azog");
	Hobbit.beRepaired(4);
	Hobbit.attack("Azog");
	Hobbit.takeDamage(6);
	Hobbit.attack("Azog");
	Hobbit.attack("Azog");
	Hobbit.attack("Azog");
	return 0;
}