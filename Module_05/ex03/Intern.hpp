#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern; 

typedef	AForm*	(Intern::*t_fp)(const std::string&) const;
typedef	struct	s_maker	t_maker;

/////// STRUCTURE ///////

struct s_maker
{
	std::string	const	key;
	t_fp const			fp;
};

/////// CLASS ///////

class Intern { 

public:
	Intern();
	~Intern();
	Intern(Intern const &);

	Intern & operator=(Intern const &);

	AForm * makeForm(std::string const &, std::string const &);

	class FormNotRecognised : public std::exception {
	public:
		virtual const char* what() const throw() {return _CORAL  "Intern made a typo:" _BOLD " Form name not recognised!\n" _END;}
	};

private:
	static t_maker	const	_search[];

	AForm * makePPF(std::string const &) const ;
	AForm * makeRRF(std::string const &) const ;
	AForm * makeSCF(std::string const &) const ;
};

#endif