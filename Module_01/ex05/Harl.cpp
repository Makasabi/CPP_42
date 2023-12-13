#include "Harl.hpp"

Harl::Harl ( void ) {

	// std::cout << "Harl is born" << std::endl;
}

Harl::~Harl ( void ) {

	// std::cout << "Harl is dead" << std::endl;
}

// t_mssg const Harl::_search[] = {
// 	{std::string("DEBUG"), &Harl::debug},
// 	{std::string("INFO"), &Harl::info},
// 	{std::string("WARNING"), &Harl::warning},
// 	{std::string("ERROR"), &Harl::error},
// 	{std::string(""), NULL},
// };

void Harl::complain( std::string level ){

	static std::string searchStr [] = {"DEBUG", "INFO", "WARNING", "ERROR", ""};
	static void (Harl::*fPtr[4])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; searchStr[i].size() != 0; i++)
		if (level == searchStr[i])
			return (this->*fPtr[i])();
			// return (this->*Harl::_search[i].fp)();
	std::cout << _PURPLE << _BOLD << "ALERT !" << _END << std::endl;
	std::cout << "Miranda is complaining in an unrecognised way..." << std::endl;
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
