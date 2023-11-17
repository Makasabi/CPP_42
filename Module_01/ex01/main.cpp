#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	
	// Testing for a single dead dude //

	Zombie aDeadGuy;

	aDeadGuy.announce();

	// Testing for many dead dude //

	Zombie* manyDeadGuys = zombieHorde(42, "Ricks");
	if (!manyDeadGuys)
		return 1;
	for (int i = 0; i < 42; i++){
		std::cout << i+1 << ": ";
		manyDeadGuys[i].announce();
	}
	delete [] manyDeadGuys;

	return 0;
}