#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm {

public:
	
	RobotomyRequestForm(std::string const &);
	RobotomyRequestForm(RobotomyRequestForm const &);
	~RobotomyRequestForm();

	RobotomyRequestForm & operator=(RobotomyRequestForm const &);

	std::string getTarget(void) const;

protected:

	virtual void	doAction(void) const;

private:
	
	RobotomyRequestForm();

	std::string const 		_target;

};



#endif