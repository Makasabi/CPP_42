# include "RPN.hpp"

RNP::RNP(std::string arg) {

	const std::string 	pattern = "0123456789 +-*/";
	std::istringstream	ss(arg);
	std::string			tmp;

	if (arg.find_first_not_of(pattern) != std::string::npos)
		throw RNP::InvalidInputException();

	while (!ss.eof() || ss.good())
	{
		ss >> tmp;
		if (tmp.size() != 1)
			throw RNP::InvalidInputException();
	}

	std::size_t i = arg.size();
	if (arg[--i] == ' ')
		arg.erase(i, 1);
	
	this->_rawData = arg;
}

RNP::~RNP(void) {
}

int	RNP::add(int left, int right) {
	return(left + right);
}

int	RNP::subtract(int left, int right) {
	return(left - right);
}

int	RNP::multiply(int left, int right) {
	return(left * right);
}

int	RNP::divide(int left, int right) {
	return(left / right);
}

int RNP::computer(void) {

	std::string 		symbols = "+-*/";
	int 				(*fp[4])(int, int) = {&RNP::add, &RNP::subtract, &RNP::multiply, &RNP::divide,};
	std::istringstream	ss(this->_rawData);

	std::string tmp;
	while (!ss.eof() && ss.good())
	{
		ss >> tmp;
		std::size_t i = symbols.find_first_of(tmp);
		if (i != std::string::npos) {
			if (this->_rpn.size() == 1)
				throw RNP::InvalidInputException();
			int right = this->_rpn.top();
			this->_rpn.pop();
			int left = this->_rpn.top();
			this->_rpn.pop();
			this->_rpn.push(fp[i](left, right));
		}
		else 
			this->_rpn.push(tmp[0] - '0');
	}

	if (this->_rpn.size() != 1)
		throw RNP::InvalidInputException();

	return this->_rpn.top();
}
