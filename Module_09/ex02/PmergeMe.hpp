#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <sstream>
# include <string>
# include <iostream>
# include <algorithm>

#include "colors.hpp"

class PmergeMe {

public:
	PmergeMe(char **argv);
	~PmergeMe();

	bool			trueDigit(std::string input);
	unsigned int	JacobsthalNumber(int n);
	bool			isSorted(void);

	/***************************/
	/*       SORT VECTOR       */
	/***************************/

	typedef std::vector<int>::iterator viterator;

	void VecSorter(int it);

	void vecSwaper(std::vector<int>::iterator bigger, std::vector<int>::iterator smaller, int size);
	void vecPrinter(std::vector<int> toPrint, std::string comment, int it);
	void vecBinarySearch(int half, std::vector<int> &chain, std::vector<int>::iterator from, std::vector<int>::iterator to);


	std::vector<int> getVec(void);



	/***************************/
	/*        SORT LIST        */
	/***************************/

	// std::list<int> & LisSorter(std::list<int> & sequence);
	// void liSwaper(std::list<int>::iterator bigger, std::list<int>::iterator smaller, int size);

	/***************************/
	/*        EXCEPTION        */
	/***************************/

	class InvalidInputException : public std::exception {
		public: virtual const char * what() const throw() {return _MAGENTA "Invalid Input" _END;} };

private:
	std::vector<int>			_vec;
	std::list<int>				_lis;

	// unsigned int				_it;

	std::vector<std::string>	_unsorted;

	PmergeMe();
	PmergeMe(PmergeMe const &src);

	PmergeMe & operator=(PmergeMe const &src);
};

#endif