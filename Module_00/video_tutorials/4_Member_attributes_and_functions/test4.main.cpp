#include "test5.hpp"
#include <iostream>

int main(void) {

	test5	instance;

	instance.foo = 42;
	std::cout << "instance.foo = [" << instance.foo << "]" << std::endl;

	instance.bar();

	return 0;
}