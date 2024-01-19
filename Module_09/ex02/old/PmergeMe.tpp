
#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

template<typename T>
void	PmergeMe::printSequence(const T& container) const {
	for (typename T::const_iterator i = container.begin(); i != container.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
}


template <typename T, typename U>
T&	PmergeMe::sortVector(U& container) {

	std::vector<MyPair<int> >		pairs;

	for (size_t i = 0; i < container.size() - 1; i += 2){
		if (container[i] > container[i + 1]) {
			std::swap(container[i], container[i + 1]);
		}
		pairs.push_back(MyPair<int>(container[i], container[i + 1]));
	}
	for (std::vector<MyPair<int> >::iterator i = pairs.begin(); i!= pairs.end(); ++i)
		std::cout << *i << std::endl;
	// fonction binarySort calling recursive function binary search -> comparing growing sized vector of pairs
	return container;
}

#endif