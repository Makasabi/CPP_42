#include "sedString.hpp"

int		main(int argc, char **argv) {

	if (argc != 4)
		return printError("Usage : ./sed <filename> <string 1> <string 2>"), 1;
	if (std::strlen(argv[2]) == 0)
		return printError("What should I replace ??"), 1;

	sedString((std::string)argv[1], (std::string)argv[2], (std::string)argv[3]);
	return 0;
}

