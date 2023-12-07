#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <unistd.h>

int main (void) {

	std::cout << _REV << "\t\t\t\t TEST POOL 1\n" << _END << std::endl;
{	
	AForm * form = new ShrubberyCreationForm("home");
	Bureaucrat guy("Paul", 138);
	Bureaucrat girl("Paula", 10);

	// Printing the infos
	std::cout << guy;
	std::cout << girl;
	std::cout << *form;

	// trying to execute the form from the form object: ERROR --> Form not signed
	try {
		form->execute(girl);
	}
	catch (std::exception &e) {
		std::cout << girl.getName() << " could not execute form " << form->getName() << " because: " << e.what();
	}

	// trying to execute the form from the bureaucrat: ERROR --> Form not signed
	guy.executeForm(*form);
	std::cout << std::endl;

	// trying to sign the form from the Bureaucrate: : SUCCESS
	guy.signForm(*form);
	std::cout << *form;

	// trying to sign the form from the Bureaucrate: : ERROR --> Already signed
	girl.signForm(*form);
	std::cout << std::endl;
	// trying to sign the form from the Bureaucrate: : ERROR --> Grade of Paul is too low
	guy.executeForm(*form);
	std::cout << std::endl;

	// Increment guy grade
	guy.incrementGrade(30);
	std::cout << std::endl;

	// trying to execute the form from the bureaucrat: SUCCESS
	guy.executeForm(*form);
	std::cout << std::endl;
	// trying to execute the form from the bureaucrat: SUCCESS
	girl.executeForm(*form);
	std::cout << std::endl;
	// Decrement girl grade
	girl.decrementGrade(128);
	std::cout << std::endl;
	// trying to sign the form from the Bureaucrate: : ERROR --> Grade of Paula is too low
	girl.executeForm(*form);
	delete form;
}
	std::cout << _REV << "\n\t\t\t\t TEST POOL 2\n" << _END << std::endl;

{
	AForm * prisonner = new PresidentialPardonForm("Jazon");
	Bureaucrat president("Zaphod Beeblebrox", 6);

	//printing infos of President and prisonner
	std::cout << president << std::endl;
	std::cout << *prisonner;

	// trying to execute the form from the bureaucrat: SUCESS
	president.signForm(*prisonner);

	std::cout << *prisonner;

	// trying to sign the form from the Bureaucrate: : ERROR --> Grade of President is too low
	president.executeForm(*prisonner);

	std::cout << std::endl;
	president.incrementGrade();
	std::cout << std::endl;
	// trying to sign the form from the Bureaucrate: : SUCESS
	president.executeForm(*prisonner);

	delete prisonner;
}

	std::cout << _REV << "\n\t\t\t\t TEST POOL 3\n" << _END << std::endl;
{
	AForm * patientone = new RobotomyRequestForm("Crazy patient");
	AForm * patienttwo = new RobotomyRequestForm("Another Crazy patient");
	Bureaucrat doctor("Dr. Even-Crazier", 35);
	Bureaucrat nurse("Mr. Nurse", 70);

	std::cout << nurse ;
	std::cout << doctor << std::endl;
	std::cout << *patientone;
	std::cout << *patienttwo;
	std::cout << std::endl;
	nurse.executeForm(*patientone);
	nurse.executeForm(*patienttwo);
	std::cout << std::endl;
	nurse.signForm(*patientone);
	nurse.signForm(*patienttwo);

	std::cout << *patientone;
	std::cout << *patienttwo;
	std::cout << std::endl;
	nurse.executeForm(*patientone);
	nurse.executeForm(*patienttwo);
	
	std::cout << std::endl;
	doctor.executeForm(*patientone);
	doctor.executeForm(*patienttwo);
	doctor.executeForm(*patientone);
	doctor.executeForm(*patienttwo);

	delete patientone;
	delete patienttwo;
}

}