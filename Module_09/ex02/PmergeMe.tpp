
#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

template<typename T>
void	PmergeMe::printSequence(const T& container) const {
	for (typename T::const_iterator i = container.begin(); i != container.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
}

// template<typename Type>
// std::vector<Type>	PmergeMe::sort(std::vector<Type> container) {

	// if (container.size() >= this->_nuVector.size())
	// 	return(container);

// 	std::vector<std::pair<int, int> > pContainer;

// 	for (size_t i = 0; i < container.size() - 1; i += 2){
// 		pContainer.push_back(std::make_pair(container[i], container[i + 1]));
// 	}

// 	for (size_t i = 0; i <= pContainer.size(); ++i) {
// 		if (PmergeMe::bigger(pContainer[i].first, pContainer[i].second))
// 			std::swap(pContainer[i].first, pContainer[i].second);
// 	}

// 	for (std::vector<std::pair<int, int> >::iterator i = pContainer.begin(); i != pContainer.end(); ++i)
// 		std::cout << i->first << ", " << i->second << std::endl;

// 	sort(pContainer);

// 	return container;
// }



#endif