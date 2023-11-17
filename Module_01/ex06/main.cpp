#include "Harl.hpp"

int	main (int ac, char **av) {

	Harl Miranda;

	if (ac != 2){
		std::cout << _PURPLE << _BOLD << "ERROR !" << _END << std::endl;
		std::cout << "Missing Argument; Usage : ./harl <complain level>" << std::endl;
		return (1);
	}
	Miranda.complain(av[1]);
	return 0;
}