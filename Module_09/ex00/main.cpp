#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2){
		std::cout << _RED << "Invalid argument count" << _END << std::endl;
		return 1;
	}
	try {
		BitcoinExchange		btcEcxge(static_cast<std::string>(argv[1]));
	}
	catch (std::exception &e) 
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

/*

1. 	Check for arg numbers
2.	Parse data base in container to be defined : Multimap  or map ?? 
3. 	Parsing arg file:
		- File does exist ?
		- Check for access rigths ?
		- Is empty or not ?
		- check first line -> to ignore or correct format ?
		- Validity or date field : 
			-> year from 2009
			-> month between 01-12
			-> day
				31 for months: 01, 03, 05, 07, 08, 10, 12
				30 for months: 04, 06, 09, 11
				28 for 02 when year%0 != 0 - else 29 days 
			std::string : "2021-09-23"
		- Validity of Value: between 0 and 1000 (1000 included ?)
	Store arg file or not ? 
4.	Compute value of detained bicoins for each line of arg file and display on std::output
5.	Exception nmanagement -> display correct message for each possible error


----> Interrupt program if input file is innaccessible or empty
ddddddfffdddff
*/