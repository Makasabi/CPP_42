#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <exception>
# include <string>
# include <sstream>
# include <utility>

# include "MyPair.hpp"
# include "colors.hpp"

template <typename T, template <typename, class> class container>
class PmergeMe {

public:

	~PmergeMe();
	PmergeMe(PmergeMe const &src);
	PmergeMe(const container<T, std::allocator<T> > &sequence);
	
	PmergeMe & operator=(PmergeMe const &src);

	void SequencePrinter(std::string state);

	container<T, std::allocator<T> >	fordJohnson();
	// container<T, std::allocator<T> >	pairSorting(void);
	// void 								pairSwaping(void);

private:
	container<T, std::allocator<T> >		_sequence;
	unsigned int 							_it;
	PmergeMe();
};

# include "PmergeMe.tpp"

#endif