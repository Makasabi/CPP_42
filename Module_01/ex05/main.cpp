#include "Harl.hpp"

int	main (int ac, char **av) {

	Harl MirandaPriestly;

	if (ac != 2){
		std::cout << _PURPLE << _BOLD << "ALERT !" << _END << std::endl;
		std::cout << "Missing Argument; Usage : ./harl <complain level>" << std::endl;
		return (1);
	}
	MirandaPriestly.complain(av[1]);
	return 0;
}