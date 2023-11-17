#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

	if (N <= 0)
		return NULL;
	Zombie*	deadGuys = new Zombie[N];

	for (int i = 0; i < N; i ++)
		deadGuys[i].setName(name);

	return deadGuys;

}