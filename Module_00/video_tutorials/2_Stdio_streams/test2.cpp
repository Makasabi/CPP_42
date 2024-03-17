#include <iostream>

// <<
// >>

int main(void) {

	char buff[512];

	std::cout << "hello world !" << std::endl;
	
	std::cout << "Input a word: ";
	std::cin >> buff;
	std::cout << "You enterd : [" << buff << "]" << std::endl;

	return 0;
}