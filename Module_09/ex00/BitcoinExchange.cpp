# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename) {

	std::ifstream	test(filename.c_str());
	if(((test.rdstate() | std::ifstream::goodbit) != 0) || test.peek() == EOF)
		throw InvalidFileException();
	test.close();
	this->_input = filename;
	fillDataBase();

}

void	BitcoinExchange::fillDataBase(void){

	std::ifstream			database("data.csv");
	if(((database.rdstate() | std::ifstream::goodbit) != 0) || database.peek() == EOF)
		throw InvalidFileException();

	std::string				line;
	while(std::getline(database, line)) {
		std::stringstream	buff(line);
		std::string			date;
		float				rate;
		if (std::getline(buff, date, ',') && buff >> rate)
			this->_btc[date] = rate;
	}
	database.close();
}

BitcoinExchange::~BitcoinExchange(void) {

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _btc(src._btc), _input(src._input) {

	return;

}


