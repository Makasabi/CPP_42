/* 
	1. analyse the input ->>> get type (char, int, float, double ?);
	-> char 'a' 'A'  or decimal notation : as 42, 42.0, 42.0f
	-> check for : -inff +inff, -inf +inf, Nan
	-> send to correct converter : switch case or pointer to function ? 
*/

#include "ScalarConverter.hpp"

int	main(int ac, char **av) {

	if (ac != 2) {
		std::cout << _MAGENTA << "Incorrect number of arguments" << _END << std::endl;
		return 1;
	}
	try {
		ScalarConverter::convert(std::string(av[1]));
	}
	catch (std::exception &e) {
		std::cout << "Error during conversion: " << e.what();
		return 1;
	}
	return 0;
}