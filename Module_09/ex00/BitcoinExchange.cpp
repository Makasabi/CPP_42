# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *filename) : _input(filename) {

	if(((_input.rdstate() | std::ifstream::goodbit) != 0) || _input.peek() == EOF)
		throw InvalidFileException();

}

BitcoinExchange::~BitcoinExchange(void) {

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
	if (*this == src)
		return;
	this->_input = src._input;
	this->_btc = src._btc;
	return;
}

