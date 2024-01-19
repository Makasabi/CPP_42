#include <string>
#include <iostream>

class Character {
	public:
		virtual void	sayHello(std::string const & target);
};

class Warrior : public Character {
	public:
		virtual void	sayHello(std::string const & target);
};

class Mage : public Character {
	public:
		virtual void	sayHello(std::string const & target);
};

class Cat
{
	//[...]
};

void Character::sayHello(std::string const & target) {

	std::cout << "hello " << target << " !" << std::endl;
}

void Warrior::sayHello(std::string const & target) {

	std::cout << "F*** off " << target << ", I don't like you !" << std::endl;
}

void Mage::sayHello(std::string const & target) {

	std::cout << "Abracadabra " << target << " !" << std::endl;
}

int main () {

	// this is OK, obviously, Warrior IS a Warrior
	Character*	a = new Warrior();

	// this is also OK because Warrior IS a Character
	Character*	b = new Character();
	Character*	c = new Mage();

	// this would NOT be ok because Character IS NOT a warrior
	// (although they are related, and W IS-A C, the reverse is not true)
	// Warrior*	c = new Character();

	// This would not be ok either because cat IS NOT a Character
	// (the are not even related)
	// Character* d= new cat();

	a->sayHello("student");

	b->sayHello("student");

	c->sayHello("student");
}