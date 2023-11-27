#include "ClapTrap.hpp"

ClapTrap::ClapTrap ( void ) : _name("Elf creature"), _hitPoint(10), _energyPoint(10), _attackDamage(0) {

	std::cout << _GREYER << "ClapTrap - Default constructor called: " << _name << " is born" << _END << std::endl;
	return;
}

ClapTrap::ClapTrap( std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {

	std::cout << _GREYER << "ClapTrap - Parametric constructor called: " << _name << " is born" << _END << std::endl;
	return;
}

ClapTrap::ClapTrap( ClapTrap const & src) {

	std::cout << _GREYER << "ClapTrap - Copy constructor called: " << _name << " is born" << _END << std::endl;
	*this = src;
	return;
}

ClapTrap::~ClapTrap ( void ) {

	std::cout << _GREYER << "ClapTrap - Destructor called on " << _name << _END << std::endl;
	return ;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src) {

	_name = src.getName();
	_hitPoint = src.getHitPoint();
	_energyPoint = src.getEnergyPoint();
	_attackDamage = src.getAttackDamage();
	return *this;
}

std::string	ClapTrap::getName( void ) const {
	
	return this->_name;
}

int	ClapTrap::getHitPoint( void ) const {
	
	return this->_hitPoint;
}

int ClapTrap::getEnergyPoint( void ) const {

	return this->_energyPoint;
}

int ClapTrap::getAttackDamage( void ) const {

	return this->_attackDamage;
}

void ClapTrap::setHitPoint(int n) {

	this->_hitPoint = n;
	return;
}

void ClapTrap::setEnergyPoint(int n) {

	this->_energyPoint = n;
	return;
}

void ClapTrap::setAttackDamage(int n) {

	this->_attackDamage = n;
	return;
}

void ClapTrap::attack(const std::string& target) {
	
	if (getEnergyPoint() == 0) {
		std::cout << _MAGENTA << _name << " doesn't have enough energy for this !" << _END << std::endl;
		return;
	}
	std::cout << _YELLOW << "\n🏹 " << _name << " attacks " << target << ", causing [" << _attackDamage << "] points of damage! 🏹" << _END << std::endl;
	setEnergyPoint(getEnergyPoint() - 1);
	std::cout << "\t🍃 " << _name << "'s remaining energy points:\t[" << _energyPoint << "]" << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount) {

	int remains = getHitPoint() - amount;
	if (remains <= 0) {
		std::cout << "\n" << _MAGENTA << _BOLD << _name << " has been defeated" << _END << std::endl;
		return ;
	}
	std::cout << _RED << "\n💥 " << _name << " takes a hit, causing [" << amount << "] points of damage!💥" << _END << std::endl;
	setHitPoint(this->getHitPoint() - amount);
	std::cout << "\t🛡️  " << _name << "'s remaining Hit points:\t[" << _hitPoint << "]" << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (getEnergyPoint() == 0) {
		std::cout << "\n" << _MAGENTA << _name << " doesn't have enough energy for this !" << _END << std::endl;
		return;
	}
	std::cout << _EMMERALD << "\n 🧚 " << _name << " gets healed and regains [" << amount << "] hit points 🧚" << _END << std::endl;
	setEnergyPoint(getEnergyPoint() - 1);
	std::cout << "\t🍃 " << _name << "'s remaining energy points:\t[" << _energyPoint << "]" << std::endl;
	setHitPoint(getHitPoint() + amount);
	std::cout << "\t🛡️  " << _name << "'s remaining Hit points:\t[" << _hitPoint << "]" << std::endl;
	return;
}