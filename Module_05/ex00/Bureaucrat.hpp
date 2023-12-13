#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class Bureaucrat {

public:

	Bureaucrat(std::string const &, unsigned char const);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &);

	Bureaucrat & operator=(Bureaucrat const &);

	std::string getName(void) const;
	unsigned char getGrade(void) const;

	void setName(std::string const);
	void setGrade(unsigned char const);

	void incrementGrade(); //--
	void incrementGrade(unsigned char); // - n

	void decrementGrade(); // ++
	void decrementGrade(unsigned char); // + n

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() { return _RED "Grade too high!\n" _END;}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {return _RED "Grade too low!\n" _END;}
	};

private:

	Bureaucrat();

	std::string const	_name;
	unsigned char		_grade;

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif