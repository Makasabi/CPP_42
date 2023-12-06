#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"


# define TRUE _FOREST_GREEN "YES" _END
# define FALSE _RED "NO" _END
class Bureaucrat;

class Form {

public:
	Form();
	Form(std::string const &, unsigned char const, unsigned char const);
	Form(Form const &);
	~Form();

	Form & operator=(Form const &);

	std::string 	getName(void) const;
	bool			getAuthograph(void) const;
	unsigned char	getGradeSign(void) const;
	unsigned char	getGradeExec(void) const;

	void			beSigned(Bureaucrat const &);

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw() { return _RED "Grade too high!\n" _END;
			}
	};

	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw() {return _RED "Grade too low!\n" _END;}
	};

	class AlreadySigned : public std::exception {
		virtual const char* what() const throw() {return _ORANGE "Form is already signed!\n" _END;}
	};

private:
	std::string const	_name;
	bool				_authograph;
	unsigned char const	_gradeSign;
	unsigned char const	_gradeExec;

};

std::ostream & operator<<(std::ostream & o, Form const & rhs);


#endif