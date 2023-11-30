#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main() {
{
	Animal* meta = new Animal();
	Animal* a = new Cat();
	Animal* b = new Dog();

	std::cout << meta->getType() << std::endl;
	meta->makeSound();

	std::cout << a->getType() << std::endl;
	a->makeSound();

	std::cout << b->getType() << std::endl;
	b->makeSound();

	delete meta;
	delete a;
	delete b;
}
	std::cout << std::endl;
{
	WrongAnimal* y = new WrongAnimal();
	WrongAnimal* x = new WrongCat("WrongCat");

	std::cout << y->getType() << std::endl;
	y->makeSound();

	std::cout << x->getType() << std::endl;
	x->makeSound();

	delete y;
	delete x;
}
	return 0;
}