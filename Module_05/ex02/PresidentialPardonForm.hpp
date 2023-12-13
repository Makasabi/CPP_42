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

protected:

	virtual void	doAction(void) const;

private:
	
	PresidentialPardonForm();

	std::string const		_target;

};



#endif