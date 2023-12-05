#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat {

public:

	Bureaucrat(void);
	Bureaucrat(std::string const &);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &);

	Bureaucrat & operator=(Bureaucrat const &);

	std::string getName(void) const;
	unsigned char getGrade(void) const;

	void setGrade(unsigned char);

	void incrementGrade(); //--
	void incrementGrade(unsigned char); // - n

	void decrementGrade(); // ++
	void decrementGrade(unsigned char); // + n

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw() {return "too high!\n";}
	};

	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw() {return "too low!\n";}
	};

private:

	std::string			_name;
	unsigned char		_grade;

};

// std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {
	
// 	o << rhs.getGrade() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
// 	return o;
// }


#endif