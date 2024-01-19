#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {
}

void ScalarConverter::printInf(std::string arg) {
	
	bool sign = true;

	if (arg.at(0) == '-')
		sign = false;
	std::cout << "Char:\t" << "impossible" << std::endl;
	std::cout << "Int:\t" << "impossible" << std::endl;
	std::cout << "Float:\t" << (sign==true?"inff":"-inff") << std::endl;
	std::cout << "Double:\t" << (sign==true?"inf":"-inf") << std::endl;
}

void ScalarConverter::printNan(void) {

	std::cout << "Char:\t" << "impossible"  << std::endl;
	std::cout << "Int:\t" << "impossible"  << std::endl;
	std::cout << "Float:\t" << "nanf" << std::endl;
	std::cout << "Double:\t" << "nan" << std::endl;
}

void ScalarConverter::printChar(std::string arg) {

	char c = arg[0];
	std::cout << "Char:\t'" << c << "'" << std::endl;
	std::cout << "Int:\t" << static_cast<int>(c) << std::endl;
	std::cout << "Float:\t" << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "Double:\t" << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::printInt(std::string arg) {

	if (arg.size() > 11 )
		throw ScalarConverter::IntOverflowException();
	long l = std::atol(arg.c_str());
	if (l > 2147483647 || l < -2147483648)
		throw ScalarConverter::IntOverflowException();
	int i = static_cast<int>(l);
	if (i == 0 ||(i >= 32 && i <= 127))
		std::cout << "Char:\t'" << static_cast<char>(i) <<"'"<< std::endl;
	else
		std::cout << "Char:\t" << "impossible" << std::endl;
	std::cout << "Int:\t" << i << std::endl;
	std::cout << "Float:\t" << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "Double:\t" << static_cast<double>(i) << ".0" << std::endl;
}


void ScalarConverter::printFloat(std::string arg) {

	float f = static_cast<float>(std::atof(arg.c_str()));
	if (f == std::numeric_limits<float>::infinity() 
	|| f == (-1 * std::numeric_limits<float>::infinity())) {
		return ScalarConverter::printInf(arg);
	}
	if (f == 0 ||(f >= 32 && f <= 127))
		std::cout << "Char:\t'" << static_cast<char>(f) <<"'"<< std::endl;
	else
		std::cout << "Char:\t" << "impossible" << std::endl;
	double d = std::atof(arg.c_str());
	if (d < -2147483648 || d > 2147483647)
		std::cout << "Int:\t" << "overflowed" << std::endl;
	else
		std::cout << "Int:\t" << static_cast<int>(d) << std::endl;
	if (arg.find(".0f") != std::string::npos) {
		std::cout << "Float:\t" << f << ".0f" << std::endl;
		std::cout << "Double:\t" << static_cast<double>(f) << ".0" << std::endl;
	}
	else {
		std::cout << "Float:\t" << f << (arg.find_first_of(".") != std::string::npos?"f":".0f") << std::endl;
		std::cout << "Double:\t" << static_cast<double>(f) << (arg.find_first_of(".") == std::string::npos?".0":"") << std::endl;
	}
}

void ScalarConverter::printDouble(std::string arg) {

	bool sign = true;

	if (arg.at(0) == '-')
		sign = false;
	double d = std::atof(arg.c_str());
	if (d == std::numeric_limits<double>::infinity() 
	|| d == (-1 * std::numeric_limits<double>::infinity())) {
		return ScalarConverter::printInf(arg);
	}
	if (d == 0 ||(d >= 32 && d <= 127))
		std::cout << "Char:\t'" << static_cast<char>(d) <<"'"<< std::endl;
	else
		std::cout << "Char:\t" << "impossible" << std::endl;
	if (d < -2147483648 || d > 2147483647)
		std::cout << "Int:\t" << "overflowed" << std::endl;
	else
		std::cout << "Int:\t" << static_cast<int>(d) << std::endl;
	if (arg.at(arg.size()-1) == '0' && arg.at(arg.size()-2) == '.') {
		if (static_cast<float>(d) == std::numeric_limits<float>::infinity()
		|| static_cast<float>(d) == std::numeric_limits<float>::infinity() * -1)
			std::cout<< "Float:\t" << static_cast<float>(d) << "f" << std::endl;
		else
			std::cout<< "Float:\t" << static_cast<float>(d) << ".0f" << std::endl;
		std::cout<< "Double:\t" << d << ".0" << std::endl;
	}
	else {
		std::cout << "Float:\t" << static_cast<float>(d) << "f" << std::endl;
		std::cout << "Double:\t" << d << std::endl;
	}
}

e_type ScalarConverter::whatNumber(std::string arg) {

	int		i = 0;
	bool	decim = false;

	if (arg.at(0) == '+' || arg.at(0) == '-')
		i++;
	for (; i < static_cast<int>(arg.size()); i++) {
		if (arg.at(i) == 'f' && std::isdigit(arg.at(i - 1))
			&& ((i + 1) == static_cast<int>(arg.size()))) {
			return FLOAT;
		}
		else if (arg.at(i) == '.') {
			if (decim == false)
				decim = true;
			else
				throw ScalarConverter::WrongFormatException();
		}
		else if (!std::isdigit(arg.at(i)))
			throw ScalarConverter::WrongFormatException();
	}
	if (decim == true)
		return DOUBLE;
	return INT;
}

e_type	ScalarConverter::findType(std::string arg) {

	if (arg == "+inf" || arg == "-inf" 
	|| arg == "+inff" || arg == "-inff")
		return INF;
	else if (arg == "nan" || arg == "nanf")
		return NAN;
	else if (arg.size() == 1 && std::isprint(arg.at(0)) != 0 && std::isdigit(arg.at(0)) == 0)
		return CHAR;
	else 
		return ScalarConverter::whatNumber(arg);
}

void	ScalarConverter::convert(std::string arg){

	switch (findType(arg)) {
		case 0 :
			ScalarConverter::printChar(arg);
			break;
		case 1 :
			ScalarConverter::printInt(arg);
			break;
		case 2 :
			ScalarConverter::printFloat(arg);
			break;
		case 3 :
			ScalarConverter::printDouble(arg);
			break;
		case 4 :
			ScalarConverter::printInf(arg);
			break;
		case 5 :
			ScalarConverter::printNan();
			break;
		default : 
			throw ScalarConverter::WrongFormatException();
	}
}
