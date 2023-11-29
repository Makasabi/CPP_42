#include <string>
#include <iostream>

// Abstract class - can not be instancied
class ACharacter { // A for Abstract
	
	private:
		std::string _name;
	public:
		virtual void	attack(std::string const & target) = 0; // " = 0" means no implementation of this method !
		void			sayHello(std::string const & target);

};

class Warrior : public ACharacter
{
	public:
		virtual void	attack(std::string const & target);
};

void ACharacter::sayHello(std::string const & target) {
	
	std::cout << "hello " << target << "!" << std::endl;
}

void Warrior::attack(std::string const & target) {

	std::cout << "Attacks " << target << " with a sword!" << std::endl;
}

// class ICoffeMaker { //I for Interface (no attributes in Interfaces)

// 	public:
// 		virtual void	fillWaterTank(IWaterSource * src) = 0;
// 		virtual ICoffee	makeCoffee(std::string const & type) = 0;
// };

int main () {

	ACharacter*	a = new Warrior();

	// This would ne be OK because ACharacter is Abstract
	// ACharacter* b = new ACharacter();

	a->sayHello("strudent");
	a->attack("Roger");

}