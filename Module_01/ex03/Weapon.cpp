#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "colors.hpp"

Weapon::Weapon() {

	std::cout << "weapon created" << std::endl;
}

Weapon::~Weapon() {

	std::cout << _RED << "weapon destroyed: " << _type << _END << std::endl;
}

Weapon::Weapon(const std::string& type) : _type(type) {

	std::cout << _BLUE << "weapon created: " << _type << _END <<  std::endl;
}

const std::string&	Weapon::getType(void) const {

	return _type;
}

void				Weapon::setType(std::string type) {

	this->_type = type;
}


