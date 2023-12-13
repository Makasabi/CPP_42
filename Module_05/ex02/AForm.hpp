#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

# define TRUE _FOREST_GREEN "YES" _END
# define FALSE _RED "NO" _END

class Bureaucrat;

class AForm {

public:
	AForm(std::string const &, unsigned char, unsigned char);
	AForm(AForm const &);
	virtual ~AForm();

	AForm & operator=(AForm const &);

	std::string 	getName(void) const;
	bool			getAuthograph(void) const;
	unsigned char	getGradeSign(void) const;
	unsigned char	getGradeExec(void) const;

	void			beSigned(Bureaucrat const &);
	virtual void	execute(Bureaucrat const & executor) const;

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw() { return _RED "Grade too high!\n" _END;}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {return _RED "Grade too low!\n" _END;}
	};

	class AlreadySigned : public std::exception {
	public:
		virtual const char* what() const throw() {return _ORANGE "AForm is already signed!\n" _END;}
	};

	class NotSigned : public std::exception {
	public:
		virtual const char* what() const throw() {return _ORANGE "is not signed signed!\n" _END;}
	};

protected:
	virtual void	doAction(void) const = 0;

private:

	AForm();

	std::string const	_name;
	bool				_isSigned;
	unsigned char const	_gradeSign;
	unsigned char const	_gradeExec;

};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif