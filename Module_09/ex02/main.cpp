#include "PmergeMe.hpp"

int main (int argc, char **argv) {

	if (argc == 1){
		std::cout << _MAGENTA "Invalid argument count" _END << std::endl;
		return 1;
	}
	try {
		PmergeMe	algo(argv);
		// std::cout << "is it sorted ? " << (algo.isSorted(algo.getVec())?"yes":"no") << std::endl;
		// algo.setVec(algo.fordJohnson(algo.getVec(), 2));
		algo.computer();
		// std::cout << "is it sorted ? " << (algo.isSorted(algo.getVec())?"yes":"no") << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _MAGENTA "Error: " << e.what() << _END << std::endl;
	}
}