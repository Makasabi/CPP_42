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

protected:

	virtual void	doAction(void) const;

private:
	
	ShrubberyCreationForm();

	std::string const 		_target;

};



#endif