#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
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

	virtual void	execute(Bureaucrat const & executor) const;
	virtual void	doAction(void) const;


private:
	
	ShrubberyCreationForm();

	std::string const 		_target;

};



#endif