#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv) {

	int		input;
	int		i = 1;

	while(argv[i])
	{
		if (PmergeMe::trueDigit(argv[i]) == true){
			this->_input.push_back(static_cast<std::string>(argv[i]));
			std::istringstream ss(static_cast<std::string>(argv[i]));
			ss >> input;
			if (input < 0)
				throw PmergeMe::InvalidInputException();
			this->_nuList.push_back(input);
			this->_nuVector.push_back(input);
		}
		else
			throw PmergeMe::InvalidInputException();
		i++;
	}
}

bool PmergeMe::trueDigit(std::string input) {

	for (std::string::iterator i = input.begin(); i != input.end(); ++i){
		if (!std::isdigit(*i))
			return false;
	}
	return true;
}

const std::vector<int> &	PmergeMe::getNuVector(void) const {
	return this->_nuVector;
}

std::vector<int> &	PmergeMe::getNuVector(void) {
	return this->_nuVector;
}

const std::vector<std::string> &	PmergeMe::getInput(void) const {
	return this->_input;
}

const std::list<int> &	PmergeMe::getNuList(void) const {
	return this->_nuList;
}

PmergeMe::~PmergeMe(void) {}