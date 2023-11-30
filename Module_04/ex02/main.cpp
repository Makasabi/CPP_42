#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main () {
// { 
// 	AAnimal *Random = new AAnimal; ---> Impossible - because AAnimal is an abstract class!
// 	Random->makeSound();
// }
{
	const int n = 4;

	AAnimal* gang[n];

	for (int i = 0; i < n; i++){
		if (i < n / 2)
			gang[i] = new Cat();
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

	return 0;
}