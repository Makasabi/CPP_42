#include <iostream>
#include <string>

int main() {
	
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "address of string:\t" << &string << std::endl;
	std::cout << "address of stringPTR:\t" << stringPTR << std::endl;
	std::cout << "address of stringREF:\t" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "content of string:\t" << string << std::endl;
	std::cout << "content of stringPTR:\t" << *stringPTR << std::endl; 
	std::cout << "content of stringREF:\t" << stringREF << std::endl;
}
