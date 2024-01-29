#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>
# include <sstream>
# include <string>
# include <iostream>
# include <algorithm>
# include <climits>
# include <ctime>
# include <sys/time.h>

# include "colors.hpp"

class PmergeMe {

public:
	PmergeMe(char **argv);
	~PmergeMe();

	void			computer(void);

	unsigned long long int chrono(void);

	bool			trueDigit(std::string input);
	unsigned int	jacobsthalNumber(int n);

	/***************************/
	/*        TEMPLATES        */
	/***************************/

	template <template <typename, typename> class Container, typename T, typename Allocator>
	bool	isSorted(Container<T, Allocator> &sequence);

	template <template <typename, typename> class Container, typename T, typename Allocator>
	void swaper(typename Container<T, Allocator>::iterator bigger, typename Container<T, Allocator>::iterator smaller, int size);

	template <template <typename, typename> class Container, typename T, typename Allocator>
	void printer(Container<T, Allocator>  toPrint, std::string comment, int it);

	template <template <typename, typename> class Container, typename T, typename Allocator>
	void binarySearch(int half, Container<T, Allocator> &chain, typename Container<T, Allocator>::iterator from, typename Container<T, Allocator>::iterator to);

	template <template <typename, typename> class Container, typename T, typename Allocator>
	Container<T, Allocator> & fordJohnson(Container<T, Allocator> &sequence, int it);

	/***************************/
	/*         VECTOR          */
	/***************************/

	std::vector<unsigned int> & getVec(void);
	void setVec(std::vector<unsigned int> & src);

	/***************************/
	/*          DEQUE          */
	/***************************/

	std::deque<unsigned int> & getDeq(void);
	void setDeq(std::deque<unsigned int> & src);

	/***************************/
	/*       EXCEPTIONS        */
	/***************************/

	class InvalidInputException : public std::exception {
		public: virtual const char * what() const throw() {return _MAGENTA "Invalid Input" _END;} };

	class AlreadySortedException : public std::exception {
		public: virtual const char * what() const throw() {return _MAGENTA "Already sorted" _END;} };

	class DuplicateEntryException : public std::exception {
		public: virtual const char * what() const throw() {return _MAGENTA "Duplicate Entry" _END;} };

private:
	std::vector<unsigned int>	_vec;
	std::deque<unsigned int>	_deq;

	std::vector<unsigned int>	_unsorted;

	PmergeMe();
	PmergeMe(PmergeMe const &src);

	PmergeMe & operator=(PmergeMe const &src);
};

# include "PmergeMe.tpp"

#endif