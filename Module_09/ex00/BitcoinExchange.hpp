#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <iostream>
# include <exception>
# include <limits>

# include "colors.hpp"

class BitcoinExchange {

public:
	/********************************* CONSTRUCTORS / DESTRUCTORS *********************************/

	BitcoinExchange(std::string filename);
	~BitcoinExchange(void);

	/********************************* METHODS *********************************/

	void	fillDataBase(void);

	void	bitcoinExchanger(void);

	bool	checkFirstLine(const std::string &line);
	
	void	dateChecker(const std::string &date);

	template<typename T>
	void	valueChecker(T & value);

	/********************************* EXCEPTIONS *********************************/

	class InvalidFileException : public std::exception {
	public : virtual const char * what() const throw() {return _RED "Invalid file" _END;} };

	class InvalidDateException : public std::exception {
	public : virtual const char * what() const throw() {return _RED "Invalid date format" _END;} };

	class DateNotReferencedException : public std::exception {
	public : virtual const char * what() const throw() {return _RED "No rate for this date" _END;} };

	class NegativeValueException : public std::exception {
	public : virtual const char * what() const throw() {return _RED "Negative value" _END;} };

	class OutOfBoundsValueException : public std::exception {
	public : virtual const char * what() const throw() {return _RED "Value is out of bounds [0 - 1000]" _END;} };

	class MissingValueException : public std::exception {
	public : virtual const char * what() const throw() {return _RED "Missing value" _END;} };

private:
	std::map <std::string, float>		_btc;
	std::string							_input;

	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const & src);

	BitcoinExchange & operator=(BitcoinExchange const & src);
};

#endif