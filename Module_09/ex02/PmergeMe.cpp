#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv) {

	unsigned int		input;
	int					i = 1;
	std::vector<unsigned int>	unsorted;

	while(argv[i]) {
		if (PmergeMe::trueDigit(argv[i]) == true){
			std::istringstream ss(static_cast<std::string>(argv[i]));
			ss >> input;
			if (input > UINT_MAX)
				throw PmergeMe::InvalidInputException();
			unsorted.push_back(input);
		}
		else
			throw PmergeMe::InvalidInputException();
		i++;
	}
	this->_unsorted = unsorted;
	if (PmergeMe::isSorted(unsorted) == true)
		throw PmergeMe::AlreadySortedException();
	std::sort(unsorted.begin(), unsorted.end());
	if (PmergeMe::isSorted(unsorted) == false)
		throw PmergeMe::DuplicateEntryException();
}

PmergeMe::~PmergeMe() {
}

bool PmergeMe::trueDigit(std::string input) {

	for (std::string::iterator i = input.begin(); i != input.end(); ++i){
		if (!std::isdigit(*i))
			return false;
	}
	return true;
}

unsigned int	PmergeMe::jacobsthalNumber(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthalNumber(n - 1) + 2 * jacobsthalNumber(n - 2);
}

unsigned long long int PmergeMe::chrono(void) {
	struct timeval	chrono;
	gettimeofday(&chrono, NULL);
	return(chrono.tv_sec * 1000000 + chrono.tv_usec);
}

void	PmergeMe::computer(void)
{
	unsigned long long int	vTime;
	unsigned long long int	dTime;

	printer(this->_unsorted, _BOLD "Before" _END, 0);

	vTime = chrono();
	for (std::vector<unsigned int>:: iterator i = this->_unsorted.begin(); i != this->_unsorted.end(); ++i)
		this->_vec.push_back(*i);
	this->_vec = fordJohnson(this->_vec, 2);
	vTime = chrono() - vTime;

	dTime = chrono();
	for (std::vector<unsigned int>:: iterator i = this->_unsorted.begin(); i != this->_unsorted.end(); ++i)
		this->_deq.push_back(*i);
	this->_deq = fordJohnson(this->_deq, 2);
	dTime = chrono() - dTime;

	printer(this->_vec, _BOLD "\nAfter" _END, 0);

 	std::cout << "\nTime to process a range of " << this->_vec.size() << " elements with std::vector<unsigned int>: " << _BOLD  _PINK << vTime << " us" << _END <<  std::endl;
 	std::cout << "Time to process a range of " << this->_vec.size() << " elements with std::deque<unsigned int>: " << _BOLD _PINK << dTime << " us" << _END <<  std::endl;
}
