#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Elf creature"), _hitPoint(10), _energyPoint(10), _attackDamage(0) {

	std::cout << _GREYER << "ClapTrap - Default constructor called: " << _name << " is born" << _END << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {

	std::cout << _GREYER << "ClapTrap - Parametric constructor called: " << _name << " is born" << _END << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src) {

	std::cout << _GREYER << "ClapTrap - Copy constructor called: " << _name << " is born" << _END << std::endl;
	*this = src;
	return;
}

ClapTrap::~ClapTrap(void) {

	std::cout << _GREYER << "ClapTrap - Destructor called - " << _name << " has lost his will to live" << _END << std::endl;
	return ;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src) {

	_name = src.getName();
	_hitPoint = src.getHitPoint();
	_energyPoint = src.getEnergyPoint();
	_attackDamage = src.getAttackDamage();
	return *this;
}

std::string	ClapTrap::getName(void) const {
	
	return this->_name;
}

unsigned int ClapTrap::getHitPoint(void) const {
	
	return this->_hitPoint;
}

unsigned int ClapTrap::getEnergyPoint(void) const {

	return this->_energyPoint;
}

unsigned int ClapTrap::getAttackDamage(void) const {

	return this->_attackDamage;
}

void ClapTrap::attack(const std::string& target) {
	
	if (_energyPoint <= 0 || _hitPoint <= 0) {
		std::cout << _MAGENTA << _name << " doesn't have enough energy or hit points for this !" << _END << std::endl;
		return;
	}
	std::cout << _YELLOW << "\n🏹 " << _name << " attacks " << target << ", causing [" << _attackDamage << "] points of damage! 🏹" << _END << std::endl;
	_energyPoint--;
	std::cout << "\t🍃 " << _name << "'s remaining energy points:\t[" << _energyPoint << "]" << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount) {

	if ((_hitPoint - amount) > _hitPoint) {
		std::cout << "\n" << _MAGENTA << _BOLD << _name << " has been defeated" << _END << std::endl;
		_hitPoint = 0;
		return ;
	}
	std::cout << _RED << "\n💥 " << _name << " takes a hit, causing [" << amount << "] points of damage!💥" << _END << std::endl;
	_hitPoint = this->_hitPoint - amount;
	std::cout << "\t🛡️  " << _name << "'s remaining Hit points:\t[" << _hitPoint << "]" << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (_energyPoint <= 0 || _hitPoint <= 0) {
		std::cout << _MAGENTA << _name << " doesn't have enough energy or hit points for this !" << _END << std::endl;
		return;
	}
	std::cout << _EMMERALD << "\n 🧚 " << _name << " gets healed and regains [" << amount << "] hit points 🧚" << _END << std::endl;
	_energyPoint--;
	std::cout << "\t🍃 " << _name << "'s remaining energy points:\t[" << _energyPoint << "]" << std::endl;
	_hitPoint = _hitPoint + amount;
	std::cout << "\t🛡️  " << _name << "'s remaining Hit points:\t[" << _hitPoint << "]" << std::endl;
	return;
}