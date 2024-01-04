#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <fstream>
# include <exception>

# include "colors.hpp"

class BitcoinExchange {

public:
	BitcoinExchange(char *filename);
	~BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const & src);

	BitcoinExchange & operator=(BitcoinExchange const & src);

	std::map <std::string, float>	getBtc(void) const;

	// // function to get correct value from key and returns resulting value
	// float	bitcoinExchanger(std::string date, float value);

	// // trows exception if date is incorrect
	// void	dateChecker(std::string date);

	// // trows exception if value is incorrect (out of range, negative...)
	// void	valueChecker(T & value);

	class InvalidFileException : public std::exception {
	public :
		virtual const char * what() const throw() {return _RED "Invalid file" _END;}
	};

	class InvalidDateException : public std::exception {
	public :
		virtual const char * what() const throw() {return _RED "Invalid date format" _END;}
	};

	class NegativeValueException : public std::exception {
	public :
		virtual const char * what() const throw() {return _RED "Negative value" _END;}
	};

	class OutOfBoundsValueException : public std::exception {
	public :
		virtual const char * what() const throw() {return _RED "Value is out of bounds [0 - 1000]" _END;}
	};

private:
	std::map <std::string, float>		_btc;
	std::ifstream						_input;

	BitcoinExchange(void);
};

#endif