// exception::what
#include <iostream>       // std::cout
#include <exception>      // std::exception

class ooops : public std::exception {
public:
	virtual const char* what() const throw() {return "Ooops!\n";} // or 'noexcept' instead of throw()
};

class tooHigh : public std::exception {
public:
	virtual const char* what() const throw() {return "Too High!\n";} // or 'noexcept' instead of throw()
};

class tooLow : public std::exception {
public:
	virtual const char* what() const throw() {return "Too Low!\n";} // or 'noexcept' instead of throw()
};

void fct(int i) {

	if (i > 2) {
		throw tooHigh();
	}
	std::cout << "hello from fct" << std::endl;
	if (i < -2) {
		throw tooLow();
	}
	std::cout << "int looks to be betwen -2 and 2" << std::endl;
}

int main () {
	try {
		fct(1);
		std::cout << "hello " << std::endl;
		fct(-1);
		fct(-0);
		throw ooops();
	}
	catch (tooHigh& ex) {
		std::cout << ex.what();
		std::cout << "tooHigh catched" << std::endl;
	}
	catch (tooLow& ex) {
		std::cout << ex.what();
		std::cout << "tooLow catched" << std::endl;
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
		std::cout << "Another issue !" << std::endl;
	}

	std::cout << "hello kitty" << std::endl;
	return 0;
}

/*
// bad_alloc example
#include <iostream>     // std::cout
#include <new>          // std::bad_alloc

int main () {
	try
	{
		int* myarray= new int[10000];
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << '\n';
	}
	return 0;
}
*/