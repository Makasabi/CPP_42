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
		btcEcxge.bitcoinExchanger();
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}