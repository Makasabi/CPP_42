#include "Harl.hpp"

Harl::Harl ( void ) {

	// std::cout << "Harl is born" << std::endl;
}

Harl::~Harl ( void ) {

	// std::cout << "Harl is dead" << std::endl;
}

// t_mssg const Harl::_search[] = {
// 	{std::string("DEBUG"), 0, &Harl::debug},
// 	{std::string("INFO"), 1, &Harl::info},
// 	{std::string("WARNING"), 2, &Harl::warning},
// 	{std::string("ERROR"), 3, &Harl::error},
// 	{std::string(""), 4, NULL},
// };

void Harl::complain( std::string level ){

	std::string searchStr [] = {"DEBUG", "INFO", "WARNING", "ERROR", ""};
	// void (Harl::*fPtr[4])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int i = 0;

	for (; searchStr[i].size() != 0; i++)
		if (level == searchStr[i])
			break;
	switch (i) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default: 
			std::cout << _PURPLE << _BOLD << "ALERT !" << _END << std::endl;
			std::cout << "Miranda is complaining in an unrecognised way..." << std::endl;
	}
}

void Harl::debug( void ) const {

	std::cout << _FOREST_GREEN << _BOLD << "[DEBUG]" << _END << std::endl;
	std::cout << DEBUG << std::endl;
}

void Harl::info( void ) const {

	std::cout << _YELLOW << _BOLD << "[INFO]" << _END << std::endl;
	std::cout << INFO << std::endl;
}

void Harl::warning( void ) const {

	std::cout << _ORANGE << _BOLD << "[WARNING]" << _END << std::endl;
	std::cout << WARNING << std::endl;
}

void Harl::error( void ) const {

	std::cout << _RED << _BOLD << "[ERROR]" << _END << std::endl;
	std::cout << ERROR << std::endl;

}
