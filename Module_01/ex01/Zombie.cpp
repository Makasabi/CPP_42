#include "Zombie.hpp"

Zombie::Zombie( void ) : _name ("Daryl"){
}

Zombie::~Zombie( void ){

	std::cout << this->_name << " is really dead this time around." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name){
}

void	Zombie::announce( void ) {

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name) {

	this->_name = name;
}