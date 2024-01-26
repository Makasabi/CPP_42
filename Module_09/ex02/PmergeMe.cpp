#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv) {

	int		input;
	int		i = 1;

	while(argv[i])
	{
		if (PmergeMe::trueDigit(argv[i]) == true){
			this->_unsorted.push_back(static_cast<std::string>(argv[i]));
			std::istringstream ss(static_cast<std::string>(argv[i]));
			ss >> input;
			if (input < 0)
				throw PmergeMe::InvalidInputException();
			this->_lis.push_back(input);
			this->_vec.push_back(input);
		}
		else
			throw PmergeMe::InvalidInputException();
		i++;
	}
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

unsigned int	PmergeMe::JacobsthalNumber(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return JacobsthalNumber(n - 1) + 2 * JacobsthalNumber(n - 2);
}

bool	PmergeMe::isSorted(void) 
{
	for (viterator i = this->_vec.begin(); i != this->_vec.end() - 1; ++i){
		if (*i > *(i + 1))
			return false;
	}
	return true;
}

/***************************/
/*         VECTOR          */
/***************************/

std::vector<int> PmergeMe::getVec(void) {
	return this->_vec;
}

void PmergeMe::VecSorter(int it){

	if (this->_vec.size()/it == 0)
		return ;

	// std::cout << "\nit = " << it << std::endl;
	// vecPrinter(this->_vec, "Unsorted pairs:", it);

	int		half = it / 2;

	for (viterator i = this->_vec.begin(); i < this->_vec.end(); i += it)
	{
		if (i + it > this->_vec.end())
			break;
		if (*(i + half - 1) > *(i + it - 1))
			vecSwaper(i, i + half, half);
	}

	// vecPrinter(this->_vec,"sorted pairs:", it);

	this->VecSorter(it*2);

	// std::cout << "\nit = " << it << std::endl;
	// std::cout << "half = " << half << std::endl;
	// vecPrinter(this->_vec,"out of reccurssion:", it);

	std::vector<int>	main , pend, odd;

	// std::cout << "iterator to begining of odd : " <<  this->_vec.size() - (this->_vec.size() % it) << std::endl;
	for (viterator i = this->_vec.end() - (this->_vec.size() % it); i < this->_vec.end(); ++i)
		odd.push_back(*i);

	int	divider = 0;
	for (viterator i = this->_vec.begin(); i < this->_vec.end() - (this->_vec.size() % it); i += half)
	{
		for(int j = 0; j < half; ++j)
		{
			if (divider % 2 == 0)
				pend.push_back(*(i + j));
			if (divider % 2 != 0)
				main.push_back(*(i + j));
		}
		divider++;
	}
	// vecPrinter(main, "main:", half);
	// vecPrinter(pend, "pend:", half);
	// vecPrinter(odd, "odd:", half);

	std::vector<int> res = main;

	int index, js, prevjs = 0, n = 2;

	while(main.size() != this->_vec.size() - odd.size())
	{
		js = JacobsthalNumber(n);
		index = js;
		while (index > prevjs && index >= 1){
			if (pend.begin() + ((index - 1) * half) >= pend.end())
				index--;
			else {
				vecBinarySearch(half, main, pend.begin()+((index -1) * half), pend.begin() + ((index -1) * half) + half -1);
				index--;
			}
		}
		prevjs = js;
		n++;
	}

	if (odd.size() < static_cast<size_t>(half) || odd[half -1] > main.back()){
		for (viterator i = odd.begin(); i != odd.end(); ++i)
			main.push_back(*i);
	}
	else {
		// std::cout << "odd insertion compare to : " << odd[half - 1] << std::endl;
		if (odd[half -1] < main.back()) {
			vecBinarySearch(half, main, odd.begin(), odd.begin() + half - 1);
			for (viterator i = odd.begin()+ half; i != odd.end(); ++i)
				main.push_back(*i);
		}
	}
	this->_vec = main;
	vecPrinter(this->_vec, "Res:", 0);
	// std::cout << "is it sorted ? " << (isSorted()?"yes":"no") << std::endl;
	return ;

}

void PmergeMe::vecBinarySearch(int half, std::vector<int> &chain, viterator from, viterator to)
{
	viterator start = chain.begin() + half - 1;
	viterator end = chain.end() - 1;
	viterator mid;
	
	while (start != end)
	{
		mid = start + ((end - start) / half / 2) * half;
		if (*mid < *to)
			start = mid + half;
		else
			end = mid;
	}
	// std::cout << "comparing *mid : " << *mid << " to : " << *to << std::endl;
	chain.insert(start - half + 1, from, to + 1);
}


void PmergeMe::vecSwaper(viterator bigger, viterator smaller, int size){

	for (; size > 0; size--)
	{
		std::swap(*bigger, *smaller);
		bigger++;
		smaller++;
	}
}

void PmergeMe::vecPrinter(std::vector<int> toPrint, std::string comment, int it){
	
	std::cout << comment << std::endl;
	for (size_t i = 0; i < toPrint.size(); i++)
	{
		if (it == 0)
			;
		else if (i % it == 0)
			std::cout << "| ";
		std::cout << toPrint[i] << " ";
	}
	std::cout << std::endl;
}
