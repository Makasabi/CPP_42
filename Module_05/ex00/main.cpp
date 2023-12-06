#include "Bureaucrat.hpp"

int main (void) {

{
	Bureaucrat one;
	std::cout << one;
	std::cout << std::endl;

	one.decrementGrade(80);
	std::cout << std::endl;
	one.decrementGrade();
	std::cout << std::endl;

	Bureaucrat oneBis(one);
	std::cout << "OneBis " << oneBis;
	oneBis.incrementGrade(22);
	std::cout << "One " <<one;
}
	std::cout << "\n\n" << std::endl;
{
	Bureaucrat two("Sasha", 165);
	std::cout << two;
}
	std::cout << "\n\n" << std::endl;
{
	Bureaucrat three;

	try {
		three.setGrade(188);
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
	}
}
}