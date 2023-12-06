#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void) {

{	
	Bureaucrat	officerOne("Henri", 51);
	Bureaucrat	officerTwo("Henriette", 140);

	Form		adm("Adm42", 50, 100);
	Form		piscine("Piscine42", 144, 50);

	std::cout << officerOne;
	std::cout << officerTwo;
	std::cout << std::endl;
	std::cout << adm;
	std::cout << piscine;

	officerOne.signForm(adm);
	std::cout << std::endl;
	officerOne.incrementGrade();
	std::cout << std::endl;
	officerOne.signForm(adm);

	std::cout << std::endl;
	std::cout << adm;


	officerTwo.signForm(adm);
	std::cout << std::endl;
	officerTwo.signForm(piscine);

	std::cout << piscine;

	officerTwo.decrementGrade(5);

	Form piscine2(piscine);

	std::cout << piscine2;

	officerTwo.signForm(piscine2);
	officerOne.signForm(piscine2);

	std::cout << piscine2;
}



}