#include "Bureaucrat.hpp"

int main (void) {

	std::cout << _REV << "\t\t\t\t TEST POOL 1\n" << _END << std::endl;
	{
		try {
			Bureaucrat one("Richard", 195);
			std::cout << one;
			std::cout << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what();
		}

		try {
			Bureaucrat one("Belinda", 50);
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
		catch (std::exception &e) {
			std::cout << e.what();
		}
	}
	std::cout << _REV << "\t\t\t\t TEST POOL 2\n" << _END << std::endl;
	{
		try {
			Bureaucrat two("Sasha", 165);
			std::cout << two;
		}
		catch (std::exception &e) {
			std::cout << e.what();
		}
	}
	std::cout << _REV << "\t\t\t\t TEST POOL 3\n" << _END << std::endl;
	{
		Bureaucrat three("Dalida", 12);
		try {
			three.setGrade(188);
		}
		catch (std::exception& ex) {
			std::cout << ex.what();
		}
	}
}