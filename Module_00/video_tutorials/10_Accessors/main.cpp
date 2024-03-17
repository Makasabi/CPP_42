#include <iostream>
#include "Sample1.class.hpp"

int		main() {
	
	Sample1	instance;

	instance.setFoo(42);
	std::cout << "_foo is = " << instance.getFoo() << std::endl;
	instance.setFoo(-42);
	std::cout << "_foo is = " << instance.getFoo() << std::endl;
	instance.setFoo(21);
	std::cout << "_foo is = " << instance.getFoo() << std::endl;
	
	return 0;
}