#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main () {
{
	const int n = 10;

	Cat kitty;

	Animal* gang[n];

	for (int i = 0; i < n; i++){
		if (i < n / 2)
			gang[i] = new Cat(kitty);
		else
			gang[i] = new Dog();
	}

	for (int i = 0; i < n; i++) {
		std::cout << "I am a: " << gang[i]->getType() << std::endl;
		gang[i]->makeSound();
	}

	for (int i = 0; i < n; i++) {
		delete gang[i];
	}

}
{
	Cat kitty;
	Cat hello;

	hello = kitty;
}
	return 0;
}