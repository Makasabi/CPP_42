#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <unistd.h>

int main (void) {

	std::cout << _REV << "\t\t\t\t TEST POOL 1\n" << _END << std::endl;
	{
		Intern intern;
		Bureaucrat papa("papa", 1);

		// Intern tries to create a form with a wrong name : FAIL	
		try {
			AForm * form = intern.makeForm("Merry Christmas", "Grandma");
			papa.signForm(*form);
			papa.executeForm(*form);
			delete form;
		}
		catch (Intern::FormNotRecognised &e){
			std::cout << e.what();
		}

		// Intern tries to create a form with a correct name : SUCCESS
		try {
			AForm * form = intern.makeForm("presidential pardon", "eleven");
			papa.signForm(*form);
			papa.executeForm(*form);
			delete form;
		}
		catch (Intern::FormNotRecognised &e){
			std::cout << e.what();
		}
	}
	return 0;
}
