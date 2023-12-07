#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm {

public:
	
	PresidentialPardonForm(std::string const &);
	PresidentialPardonForm(PresidentialPardonForm const &);
	~PresidentialPardonForm();

	PresidentialPardonForm & operator=(PresidentialPardonForm const &);

	std::string getTarget(void) const;

	virtual void	execute(Bureaucrat const & executor) const;
	virtual void	doAction(void) const;


private:
	
	PresidentialPardonForm();

	std::string const		_target;

};



#endif