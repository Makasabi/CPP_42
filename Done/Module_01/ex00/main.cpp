#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void) {

	// Testing newZombie //

	Zombie* aDeadGuy = newZombie("Daryl");

	aDeadGuy->announce();
	delete aDeadGuy;

	// Testing randomChump //

	randomChump("Rick");

	return 0;
}