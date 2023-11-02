#include "test5.hpp"
#include <iostream>

int main(void) {

	test5	instance;
	test5	instance2;

	// instance.foo = 21;
	// std::cout << "instance.foo = [" << instance.foo << "]" << std::endl;
	// std::cout << "instance.color = [" << instance.color << "]" << std::endl;
	
	// std::cout << "Paint it all white\n";
	// instance.color = "white";
	// std::cout << "instance.color = [" << instance.color << "]" << std::endl;
	instance.paint("blue");
	std::cout << "instance.color = [" << instance.color << "]" << std::endl;
	std::cout << "instance2.color = [" << instance2.color << "]" << std::endl;

	instance.bar();

	return 0;
}