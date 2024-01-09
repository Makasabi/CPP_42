# include "RPN.hpp"

int main (int argc, char **argv) {

	if (argc != 2){
		std::cout << _RED << "Invalid argument count" << _END << std::endl;
		return 1;
	}
	try {
		RNP		calculator(argv[1]);
		int result = calculator.computer();
		std::cout << result << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}