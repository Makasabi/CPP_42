#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm {

public:
	
	ShrubberyCreationForm(std::string const &);
	ShrubberyCreationForm(ShrubberyCreationForm const &);
	~ShrubberyCreationForm();

	ShrubberyCreationForm & operator=(ShrubberyCreationForm const &);

	std::string getTarget(void) const;

	void execute(Bureaucrat const & executor) const;

private:
	
	ShrubberyCreationForm();

	std::string const 		_target;

};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs);


#endif