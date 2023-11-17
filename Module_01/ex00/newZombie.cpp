#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {

	Zombie*		deadGuy = new Zombie(name);

	return (deadGuy);
}