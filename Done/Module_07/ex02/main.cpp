#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Array.hpp"

int main (void) {
{
	std::cout << _MAGENTA <<_REV << "Test with String\n" << _END << std::endl;

	Array<std::string> str(7);
	str[0] = "zero";
	str[1] = "one";
	str[2] = "one";
	str[3] = "two";
	str[4] = "three";
	str[5] = "five";
	str[6] = "eight";
	std::cout << str;

	try {
		std::cout << "Trying to access index 42 of array" << std::endl;
		str[42] = "something";
	}
	catch (const std::exception& e) {
		std::cout << e.what();
	}
}
	std::cout << std::endl;
{
	std::cout << _MAGENTA <<_REV << "\nTest with Int\n" << _END << std::endl;

	Array<int> ints(5);
	srand(time(NULL));
	for (size_t i = 0; i < ints.size(); i++)
		ints[i] = rand();
	
	

	std::cout << ints;

	Array<int> doppleganger(ints);

	std::cout << "\nPrinting copy:\n" << doppleganger;

}

}

// #define MAX_VAL 750

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }