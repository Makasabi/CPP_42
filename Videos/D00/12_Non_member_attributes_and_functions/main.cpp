#include "Sample.class.hpp"
#include <iostream>

void f0( void ) {

	Sample instance;

	std::cout << "Number of instance: " << Sample::getNbInst() << std::endl;
	return;
}

void f1( void ) {

	Sample instance;

	std::cout << "Number of instance: " << Sample::getNbInst() << std::endl;
	f0();

	return;
}

int main() { 

	std::cout << "Number of instance: " << Sample::getNbInst() << std::endl;
	f1();
	std::cout << "Number of instance: " << Sample::getNbInst() << std::endl;

	return 0;
}