#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void) {
	{
		try {
			Bureaucrat	officerOne("Henri", 51);
			Bureaucrat	officerTwo("Henriette", 140);
			Form		adm("Adm42", 50, 100);
			Form		piscine("Piscine42", 144, 50);

			std::cout << officerOne;
			std::cout << officerTwo;
			std::cout << adm;
			std::cout << piscine;

// ======> Test : Sign form with a low grade
			try {
				officerOne.signForm(adm);
			}
			catch (std::exception &e) {
				std::cout << officerOne.getName() << " could not sign form [" << adm.getName() << "] because: " << e.what();
			}
			std::cout << std::endl;

// ======> Test : Increment grade of officer
			try {
				officerOne.incrementGrade();
			}
			catch (Bureaucrat::GradeTooLowException &e) {
				std::cout << officerOne.getName() << " could not sign form [" << adm.getName() << "] because: " << e.what();
			}

// ======> Test : Sign form with a high enough grade
			try {
				officerOne.signForm(adm);
			}
			catch (std::exception &e) {
				std::cout << officerOne.getName() << " could not sign form [" << adm.getName() << "] because: " << e.what();
			}
			std::cout << std::endl;
			std::cout << adm;

// ======> Test : Sign form that's already signed
			try {
				officerOne.signForm(adm);
			}
			catch (std::exception &e) {
				std::cout << officerOne.getName() << " could not sign form [" << adm.getName() << "] because: " << e.what();
			}
			std::cout << std::endl;

// ======> Test : Sign form with a high enough grade
			try {
				officerTwo.signForm(piscine);
			}
			catch (std::exception &e) {
				std::cout << officerTwo.getName() << " could not sign form [" << adm.getName() << "] because: " << e.what();
			}
			std::cout << piscine;

// ======> Test : Decrement grade of officer by too many levels
			try {
				officerTwo.decrementGrade(15);
			}
			catch (Bureaucrat::GradeTooLowException &e) {
				std::cout << "Could not decrement grade of [" << officerTwo.getName() << "] because: " << e.what();
			}
			std::cout << std::endl;

// ======> Test : Decrement grade of officer
			try {
				officerTwo.decrementGrade(5);
			}
			catch (Bureaucrat::GradeTooLowException &e) {
				std::cout << "Could not decrement grade of [" << officerTwo.getName() << "] because: " << e.what();
				}
			std::cout << std::endl;

// =====> Test : Copy a form and check if the copied form has corect grades but is unsigned.
			Form piscine2(piscine);
			std::cout << piscine2;

// ======> Test : Sign form with a low grade
			try {
				officerTwo.signForm(piscine2);
			}
			catch (std::exception &e) {
				std::cout << officerTwo.getName() << " could not sign form [" << piscine2.getName() << "] because: " << e.what();
			}

// ======> Test : Sign form with a low grade
			try {
				officerOne.signForm(piscine2);
			}
			catch (std::exception &e) {
				std::cout << officerOne.getName() << " could not sign form [" << piscine2.getName() << "] because: " << e.what();
			}

			std::cout << piscine2;
			}

		catch (std::exception &e) {
			std::cout << "error upon building object: " << e.what();
		}
	}
}