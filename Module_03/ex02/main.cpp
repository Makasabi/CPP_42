#include "colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {

	ClapTrap Hobbit("Bilbo Baggins");
	ScavTrap Orc( "Azog" );
	FragTrap Elf( "Legolas" );

	Elf.highFivesGuys();

	Orc.attack(Elf.getName());
	Elf.takeDamage(Orc.getAttackDamage());
	Elf.attack(Orc.getName());
	Orc.takeDamage(Elf.getAttackDamage());
	Orc.guardGate();
	Elf.beRepaired(20);
	Elf.attack(Orc.getName());
	Orc.takeDamage(Elf.getAttackDamage());
	Orc.attack(Elf.getName());
	Elf.takeDamage(Orc.getAttackDamage());
	Elf.attack(Orc.getName());
	Orc.takeDamage(Elf.getAttackDamage());
	Orc.attack(Elf.getName());
	Elf.takeDamage(Orc.getAttackDamage());
	Elf.attack(Orc.getName());
	Orc.takeDamage(Elf.getAttackDamage());
	Orc.attack(Elf.getName());
	return 0;
}