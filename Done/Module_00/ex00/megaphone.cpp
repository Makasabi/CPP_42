#include <iostream>
#include <string>


void str_to_upper(std::string str)
{
	int	c;
	for (int i = 0; str[i]; i++) {
		c = str[i];
		std::cout << (char)std::toupper(c);
	}
}

int main(int argc, char **argv) {
	
	(void)argv;
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; argv[i]; i++) {
			str_to_upper(argv[i]);
		}
		std::cout << std::endl;
	}
	return 0;
}

