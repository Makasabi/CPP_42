#include "PmergeMe.hpp"

int main (int argc, char **argv) {

	if (argc == 1){
		std::cout << _MAGENTA "Invalid argument count" _END << std::endl;
		return 1;
	}
	try {
		PmergeMe	algo(argv);
		algo.sortVector<std::vector<int> >(algo.getNuVector());
	}
	catch (std::exception &e) {
		std::cout << _MAGENTA "Error: " << e.what() << _END << std::endl;
	}
}