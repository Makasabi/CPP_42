#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", 145, 137), _target("target"){

	std::cout << _GREYER << _ITALIC << "ShrubberyCreationForm - Default constructor called" << _END << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("Shrubbery Creation Form", 145, 137), _target(target){

	std::cout << _GREYER << _ITALIC << "ShrubberyCreationForm - Parametric constructor called" << _END << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

	std::cout << _GREYER << _ITALIC << "ShrubberyCreationForm - Destructor called" << _END << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm("Shrubbery Creation Form", 145, 137), _target(src.getTarget()){

	std::cout << _GREYER << _ITALIC << "ShrubberyCreationForm - Copy constructor called" << _END << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const {

	return this->_target;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {

	(void)src;
	return *this;
}

void	ShrubberyCreationForm::doAction(void) const {

	std::string name = this->_target + "_shrubbery";

	std::ofstream	outfile(name.c_str());
	if((outfile.rdstate() | std::ifstream::goodbit) != 0) {
		std::cout << _RED << "error invalid outfile: " << name << _END << std::endl;
		return ;
	}

	outfile << "             /\\" << std::endl;
	outfile << "            <  >" << std::endl;
	outfile << "             \\/" << std::endl;
	outfile << "             /\\" << std::endl;
	outfile << "            /  \\" << std::endl;
	outfile << "           /++++\\" << std::endl;
	outfile << "          /  ()  \\" << std::endl;
	outfile << "          /      \\" << std::endl;
	outfile << "         /~`~`~`~`\\" << std::endl;
	outfile << "        /  ()  ()  \\" << std::endl;
	outfile << "        /          \\" << std::endl;
	outfile << "       /*&*&*&*&*&*&\\" << std::endl;
	outfile << "      /  ()  ()  ()  \\" << std::endl;
	outfile << "      /              \\" << std::endl;
	outfile << "     /++++++++++++++++\\" << std::endl;
	outfile << "    /  ()  ()  ()  ()  \\" << std::endl;
	outfile << "    /                  \\" << std::endl;
	outfile << "   /~`~`~`~`~`~`~`~`~`~`\\" << std::endl;
	outfile << "  /  ()  ()  ()  ()  ()  \\" << std::endl;
	outfile << "  /*&*&*&*&*&*&*&*&*&*&*&\\" << std::endl;
	outfile << " /                        \\" << std::endl;
	outfile << "/,.,.,.,.,.,.,.,.,.,.,.,.,.\\" << std::endl;
	outfile << "           |   |" << std::endl;
	outfile << "          |`````|" << std::endl;
	outfile << "          \\_____/" << std::endl;

	outfile.close();
}
