#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <unistd.h>

int main (void) {

	std::cout << _REV << "\t\t\t\t TEST POOL 0\n" << _END << std::endl;
{
	Intern intern;
	Bureaucrat papa("papa", 1);

	// Intern tries to create a form with a wrong name : FAIL
	try {
		AForm * form = intern.makeForm("Merry Christmas", "eleven");
		(void)form;
	}
	catch (Intern::FormNotRecognised &e){
		std::cout << e.what();
	}

	// Intern tries to create a form with a correct name : SUCCESS
	try {
		AForm * form = intern.makeForm("presidential pardon", "Grandma");
		papa.signForm(*form);
		papa.executeForm(*form);
		delete form;
	}
	catch (Intern::FormNotRecognised &e){
		std::cout << e.what();
	}
}
	std::cout << _REV << "\t\t\t\t TEST POOL 1\n" << _END << std::endl;

{	

	Bureaucrat guy("Paul", 138);
	Bureaucrat girl("Paula", 10);
	Intern intern;

	// Intern tries to create a form with a wrong name : FAIL
	try {
		AForm * form = intern.makeForm("Merry Christmas", "eleven");
		(void)form;
	}
	catch (Intern::FormNotRecognised &e){
		std::cout << e.what();
	}

	// Intern tries to create a form with an incomplete name : FAIL
	try {
		AForm * form = intern.makeForm("presidential", "eleven");
		(void)form;
	}
	catch (Intern::FormNotRecognised &e){
		std::cout << e.what();
	}

	// Intern tries to create a form with a correct name : SUCCESS
	try {
		AForm * form = intern.makeForm("shrubbery creation", "home");

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

	catch (Intern::FormNotRecognised &e){
		std::cout << e.what();
	}
}
	std::cout << _REV << "\n\t\t\t\t TEST POOL 2\n" << _END << std::endl;

{
	Bureaucrat president("Zaphod Beeblebrox", 6);
	Intern intern;

	// Intern tries to create a form with a correct name : SUCCESS
	try {
		AForm * prisonner = intern.makeForm("presidential pardon", "Jazon");

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
	catch (Intern::FormNotRecognised &e) {
		std::cout << e.what();
	}

}

	std::cout << _REV << "\n\t\t\t\t TEST POOL 3\n" << _END << std::endl;
{
	try { 

	Bureaucrat doctor("Dr. Even-Crazier", 35);
	Bureaucrat nurse("Mr. Nurse", 70);
	Intern	medicalIntern;
	AForm * patientone = medicalIntern.makeForm("robotomy request", "Crazy patient");
	AForm * patienttwo = medicalIntern.makeForm("robotomy request", "Another Crazy patient");

	//printing infos of Doctor, Nurse, patientone & patienttwo
	std::cout << nurse ;
	std::cout << doctor << std::endl;
	std::cout << *patientone;
	std::cout << *patienttwo;
	std::cout << std::endl;

	// Nurse tries to execute form : ERROR -> --> Form is not signed
	nurse.executeForm(*patientone);
	nurse.executeForm(*patienttwo);
	std::cout << std::endl;

	// Nurse tries to sign form : SUCCESS
	nurse.signForm(*patientone);
	nurse.signForm(*patienttwo);

	std::cout << *patientone;
	std::cout << *patienttwo;
	std::cout << std::endl;

	// Nurse tries to execute form : ERROR -> --> Grade of Nurse is too low
	nurse.executeForm(*patientone);
	nurse.executeForm(*patienttwo);
	std::cout << std::endl;
	
	// Doctor executes Form several times to check if the Robotomy is a success 50% of the time
	doctor.executeForm(*patientone);
	doctor.executeForm(*patienttwo);
	doctor.executeForm(*patientone);
	doctor.executeForm(*patienttwo);

	delete patientone;
	delete patienttwo;

	AForm *patientthree = medicalIntern.makeForm("shrubberycreation", "hospital");
	(void)patientthree;
	}
	catch (Intern::FormNotRecognised &e) {
		std::cout << e.what();
	}
}

}