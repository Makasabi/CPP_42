#include "Zombie.hpp"

Zombie::Zombie( void ){
}

Zombie::~Zombie( void ){

	std::cout << this->_name << " is really dead this time." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name){
}

void	Zombie::announce( void ) {

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}