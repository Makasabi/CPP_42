#ifndef RNP_HPP
# define RNP_HPP

# include <stack>
# include <string>
# include <sstream>
# include <iostream>
# include <exception>

# include "colors.hpp"

class RNP {

public:

	RNP(std::string arg);
	~RNP(void);

	int computer(void);

	static int add(int left, int right);
	static int subtract(int left, int right);
	static int multiply(int left, int right);
	static int divide(int left, int right);

	class InvalidInputException : public std::exception {
		public: virtual const char * what() const throw() {return _MAGENTA "Invalid Input" _END;} };

	class ImpossibleDivisionException : public std::exception {
		public: virtual const char * what() const throw() {return _MAGENTA "Division by 0 impossible" _END;} };

private:

	std::stack<int>	_rpn;
	std::string		_rawData;

	RNP(void);
	RNP(RNP const & src);

	RNP & operator=(RNP const & src);
};

#endif