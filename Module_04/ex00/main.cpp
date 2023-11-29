#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {

	Animal* meta = new Animal();
	Animal* a = new Cat("Cat");
	Animal* b = new Dog("Dog");

	std::cout << meta->getType() << std::endl;
	meta->makeSound();

	std::cout << a->getType() << std::endl;
	a->makeSound();

	std::cout << b->getType() << std::endl;
	b->makeSound();

	delete meta;
	delete a;
	delete b;

	return 0;
}