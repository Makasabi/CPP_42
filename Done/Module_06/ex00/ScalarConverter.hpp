#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <cstring>
#include <cstdlib>
#include <limits>
# include <iostream>

# include "colors.hpp"

enum e_type {CHAR, INT, FLOAT, DOUBLE, INF, NAN, INVALID};

class ScalarConverter {

public:

	~ScalarConverter();

	static void convert(std::string);

	class WrongFormatException : public std::exception {
	public:
		virtual const char* what() const throw() { return _RED "Unrecognised type\n" _END;}
	};

	class IntOverflowException : public std::exception {
	public:
		virtual const char* what() const throw() { return _RED "Int is overflowing\n" _END;}
	};

private:

	ScalarConverter();
	ScalarConverter(ScalarConverter const &);
	ScalarConverter operator=(ScalarConverter const &);

	static e_type findType(std::string);
	static e_type whatNumber(std::string arg);
	static void printChar(std::string arg);
	static void printInt(std::string arg);
	static void printFloat(std::string arg);
	static void printDouble(std::string arg);
	static void printInf(std::string arg);
	static void printNan(void);

};

#endif