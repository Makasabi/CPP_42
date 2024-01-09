# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename) {

	std::ifstream	test(filename.c_str());
	if(((test.rdstate() | std::ifstream::goodbit) != 0) || test.peek() == EOF)
		throw InvalidFileException();
	test.close();
	this->_input = filename;
	fillDataBase();
}

BitcoinExchange::~BitcoinExchange(void) {
}


void	BitcoinExchange::fillDataBase(void){

	std::ifstream			database("data.csv");
	if(((database.rdstate() | std::ifstream::goodbit) != 0) || database.peek() == )
		throw InvalidFileException();

	std::string				line;
	while(std::getline(database, line)) {
		std::istringstream	buff(line);
		std::string			date;
		float				rate;
		if (std::getline(buff, date, ',') && buff >> rate)
			this->_btc[date] = rate;
	}
	database.close();
}

bool	BitcoinExchange::checkFirstLine(const std::string &line) {

	std::istringstream	ss(line);
	std::string			date;
	std::string			test;
	float				value = 0;

	std::getline(ss, date, ' ');
	try {
		dateChecker(date);
		if (ss.eof() || ss.bad())
			return false;
		ss.ignore(std::numeric_limits<std::streamsize>::max(), '|');
		ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
		ss >> value;
		valueChecker(value);
	}
	catch (std::exception &e) {
		return false;
	}
	return true;
}

void	BitcoinExchange::dateChecker(const std::string &date){

	std::istringstream	ss(date);
	char				dash;
	int					year, month, day;
	int 				daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (date.size() == 0)
		throw BitcoinExchange::MissingValueException();
	ss >> year >> dash >> month >> dash >> day;

	if ((year%4 == 0 && year%100 != 0) || year %400 == 0)
		daysInMonths[2] = 29;
	if (year < 2009 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31)
		throw BitcoinExchange::InvalidDateException();
	if (day > daysInMonths[month])
		throw BitcoinExchange::InvalidDateException();
	if (year == 2024 && month > 01 && day > 7)
		throw BitcoinExchange::InvalidDateException();
	return;
}

template<typename T>
void	BitcoinExchange::valueChecker(T & value){

	if (value == 0 || value > 1000)
		throw BitcoinExchange::OutOfBoundsValueException();
	if (value < 0)
		throw BitcoinExchange::NegativeValueException();
	return;
}

void	BitcoinExchange::bitcoinExchanger(void) {

	std::ifstream	input(this->_input.c_str());
	std::string		line;
	std::string		date;
	float			value;

	if (std::getline(input, line) && checkFirstLine(line) == true){
		std::istringstream	ss(line);

		std::getline(ss, date, ' ');
		ss.ignore(std::numeric_limits<std::streamsize>::max(), '|');
		ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
		ss >> value;

		std::map<std::string, float>::iterator i = this->_btc.upper_bound(date);
		std::cout << date << " --> " << value << " --> " << (--i->second * value) << std::endl;
	}
	while(std::getline(input, line)) {
		try{
			std::istringstream	buff(line);
			std::getline(buff, date, ' ');
			dateChecker(date);
			std::cout << date << " --> ";
			buff.ignore(std::numeric_limits<std::streamsize>::max(), '|');
			buff.ignore(std::numeric_limits<std::streamsize>::max(), ' ');

			if (buff.eof() || buff.bad() || (!std::isdigit(buff.peek()) && buff.peek() != '-'))
				throw BitcoinExchange::MissingValueException();
			
			else {
				buff >> value;
				valueChecker(value);
				std::map<std::string, float>::iterator i = this->_btc.upper_bound(date);
				if (i == this->_btc.begin())
					throw BitcoinExchange::DateNotReferencedException();
				--i;
				std::cout << value << " = " << (i->second * value) << std::endl;
			}
		}
		catch (std::exception &e) {
			std::cout << _RED "Error: " << e.what() << _END << std::endl;
		}
	}
}
