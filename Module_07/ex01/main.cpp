#include "iter.hpp"
#include <string>

int main(void) {

	std::cout << _MAGENTA <<_REV << "Test with Int" << _END << std::endl;
	int		intArr[]	= {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
	size_t	intArrSize	= 16;
	::iter(intArr, intArrSize, &print);
	std::cout << std::endl;

	std::cout << _MAGENTA <<_REV << "Test with strings" << _END << std::endl;
	std::string strArr[] = {"zero", "one", "one", "two", "three", "five", "eight", "thirteen", "twenty one", "thirty four", "fifty five", "eighty nine", "hundred and fourty four"};
	size_t	strArrSize	= 13;
	::iter(strArr, strArrSize, &print);
	std::cout << std::endl;

	std::cout << _MAGENTA <<_REV << "Test with floats" << _END << std::endl;
	float		floatArr[]	= {0.01f, 1.01f, 1.01f, 2.01f, 3.01f, 5.01f, 8.01f, 13.01f, 21.01f, 34.01f, 55.01f, 89.01f, 144.01f, 233.01f, 377.01f, 610.01f};
	size_t	floatArrSize	= 16;
	::iter(floatArr, floatArrSize, &print);
	std::cout << std::endl;

	std::cout << _MAGENTA <<_REV << "Test with double" << _END << std::endl;
	double		doubleArr[]	= {0.01, 1.01, 1.01, 2.01, 3.01, 5.01, 8.01, 13.01, 21.01, 34.01, 55.01, 89.01, 144.01, 233.01, 377.01, 610.01};
	size_t	doubleArrSize	= 16;
	::iter(doubleArr, doubleArrSize, &print);
	std::cout << std::endl;

	std::cout << _MAGENTA <<_REV << "Test with char" << _END << std::endl;
	char charArr[] = {'0', '1', '1', '2', '3', '5', '8'};
	size_t	charArrSize	= 7;
	::iter(charArr, charArrSize, &print);
	std::cout << std::endl;

}