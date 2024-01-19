#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <unistd.h>

int main (void) {

	std::cout << _REV << "\t\t\t\t TEST POOL 1\n" << _END << std::endl;
{	
	try {
		AForm * form = new ShrubberyCreationForm("home");
		Bureaucrat guy("Paul", 138);
		Bureaucrat girl("Paula", 10);


// ======> Test: Printing the infos
		std::cout << guy;
		std::cout << girl;
		std::cout << *form;

// ======> Test: trying to execute the form from the form object: ERROR --> Form not signed
		try {
			form->execute(girl);
		}
		catch (std::exception &e) {
			std::cout << girl.getName() << " could not execute [" << form->getName() << "] because: " << e.what();
		}

// ======> Test: trying to execute the form from the bureaucrat: ERROR --> Form not signed
		try {
			guy.executeForm(*form);
		}
		catch (std::exception &e) {
			std::cout << guy.getName() << " could not execute [" << form->getName() << "] because: " << e.what();
		}
		std::cout << std::endl;

// ======> Test: trying to sign the form from the Bureaucrate: : SUCCESS
		try {
			guy.signForm(*form);
		}
		catch (std::exception &e) {
			std::cout << guy.getName() << " could not sign [" << form->getName() << "] because: " << e.what();
		}
		std::cout << *form;

// ======> Test: trying to sign the form from the Bureaucrate: : ERROR --> Already signed
		try {
			girl.signForm(*form);
		}
		catch (std::exception &e) {
			std::cout << girl.getName() << " could not sign [" << form->getName() << "] because: " << e.what();
		}
		std::cout << std::endl;

// ======> Test: trying to execute the form from the bureaucrat: ERROR --> Grade of Paul is too low
		try {
			guy.executeForm(*form);
		}
		catch (std::exception &e) {
			std::cout << guy.getName() << " could not execute [" << form->getName() << "] because: " << e.what();
		}
		std::cout << std::endl;

// ======> Test: Increment guy grade
		try {
			guy.incrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << "Could not increment grade of " << guy.getName() << " by [1] because: " << e.what();
		}
		std::cout << std::endl;

// ======> Test: trying to execute the form from the bureaucrat: SUCCESS
		try {
			guy.executeForm(*form);
		}
		catch (std::exception &e) {
			std::cout << guy.getName() << " could not execute [" << form->getName() << "] because: " << e.what();
		}
		std::cout << std::endl;

// ======> Test: trying to execute the form from the bureaucrat: SUCCESS
		try {
			girl.executeForm(*form);
		}
		catch (std::exception &e) {
			std::cout << girl.getName() << " could not execute [" << form->getName() << "] because: " << e.what();
		}
		std::cout << std::endl;

// ======> Test: Decrement girl grade
		try {
			girl.decrementGrade(128);
		}
		catch (std::exception &e) {
			std::cout << "Could not decrement grade of " << guy.getName() << " by [128] because: " << e.what();
		}
		std::cout << std::endl;

// ======> Test: trying to sign the form from the Bureaucrate: : ERROR --> Grade of Paula is too low
		try {
			girl.executeForm(*form);
		}
		catch (std::exception &e) {
			std::cout << girl.getName() << " could not execute [" << form->getName() << "] because: " << e.what();
		}

		delete form;
		}

	catch (std::exception &e) {
		std::cout << "Error building object: " << e.what();
	}
}

	std::cout << _REV << "\n\t\t\t\t TEST POOL 2\n" << _END << std::endl;
{
	try {
		AForm * prisonner = new PresidentialPardonForm("Jazon");
		Bureaucrat president("Zaphod Beeblebrox", 6);

	//printing infos of President and prisonner
		std::cout << president << std::endl;
		std::cout << *prisonner;

// ======> Test: trying to execute the form from the bureaucrat: SUCESS
		try {
			president.signForm(*prisonner); 
		}
		catch (std::exception &e) {
			std::cout << president.getName() << " could not sign [" << prisonner->getName() << "] because: " << e.what();
		}
		std::cout << *prisonner;

// ======> Test: trying to sign the form from the Bureaucrate: : ERROR --> Grade of President is too low
		try {
			president.executeForm(*prisonner);
		}
		catch (std::exception &e) {
			std::cout << president.getName() << " could not execute [" << prisonner->getName() << "] because: " << e.what();
		}
		std::cout << std::endl;

// ======> Test: Incrementing grade of president : SUCCESS
		try {
			president.incrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << "Could not increment grade of " << president.getName() << " by [1] because: " << e.what();
		}
		std::cout << std::endl;

// ======> Test: trying to sign the form from the Bureaucrate: : SUCESS
		try {
			president.executeForm(*prisonner);
		}
		catch (std::exception &e) {
			std::cout << president.getName() << " could not execute [" << prisonner->getName() << "] because: " << e.what();
		}

		delete prisonner;
	}
	catch (std::exception &e) {
		std::cout << "Error building object: " << e.what();
	}
}

	std::cout << _REV << "\n\t\t\t\t TEST POOL 3\n" << _END << std::endl;
{
// ======> Test: creating objects
	try {
		AForm * patientone = new RobotomyRequestForm("Crazy patient");
		Bureaucrat doctor("Dr. Even-Crazier", 35);
		Bureaucrat nurse("Mr. Nurse", 70);

// Printing objects Doctor, nurse and patien infos : 
		std::cout << nurse ;
		std::cout << doctor << std::endl;
		std::cout << *patientone;
		std::cout << std::endl;

// ======> Test: Nurse tries to execute unsigned form:
		try {
			nurse.executeForm(*patientone); }
		catch (std::exception &e) {
			std::cout << nurse.getName() << " Could not execute [" << patientone->getName() << "] because: " << e.what();
		}

		std::cout << std::endl;
		try {
			nurse.signForm(*patientone); }
		catch (std::exception &e) {
			std::cout << nurse.getName() << " Could not sign [" << patientone->getName() << "] because: " << e.what();
		}

		try {
			nurse.signForm(*patientone); }
		catch (std::exception &e) {
			std::cout << nurse.getName() << " Could not sign [" << patientone->getName() << "] because: " << e.what();
		}

		std::cout << *patientone;
		std::cout << std::endl;
		try {
			nurse.executeForm(*patientone); }
		catch (std::exception &e) {
			std::cout << nurse.getName() << " Could not execute [" << patientone->getName() << "] because: " << e.what();
		}
		
		std::cout << std::endl;

		try {
			doctor.executeForm(*patientone);
		}
		catch (std::exception &e) {
			std::cout << doctor.getName() << " Could not execute [" << patientone->getName() << "] because: " << e.what();
		}
		std::cout << std::endl;

		try {
			doctor.executeForm(*patientone);
		}
		catch (std::exception &e) {
			std::cout << doctor.getName() << " Could not execute [" << patientone->getName() << "] because: " << e.what();
		}
		std::cout << std::endl;

		try {
			nurse.incrementGrade(25);
		}
		catch (std::exception &e) {
			std::cout << "Could not increment grade of " << nurse.getName() << " by [30] because: " << e.what();
		}
		std::cout << std::endl;

		try {
			nurse.executeForm(*patientone);
		}
		catch (std::exception &e) {
			std::cout << nurse.getName() << " Could not execute [" << patientone->getName() << "] because: " << e.what();
		}
		std::cout << std::endl;

		delete patientone;
	}
	catch (std::exception &e) {
		std::cout << "Error building object: " << e.what();
	}
}
}