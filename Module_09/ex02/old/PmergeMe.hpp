#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <list>
# include <vector>
# include <exception>
# include <utility>
# include <pair>

# include "colors.hpp"
// # include "MyPair.hpp"

class PmergeMe {

public:

	PmergeMe(char **argv);
	~PmergeMe(void);

	static bool trueDigit(std::string input);

	template <typename T>
	void	printSequence(const T& container) const;

	// fonction sortVector
	template <typename T, typename U>
	T&	sortVector(U& container);

	// fonction sortList
	const std::vector<int> &			getNuVector(void) const;
	std::vector<int>& getNuVector();
	const std::vector<std::string> &	getInput(void) const;
	const std::list<int> &			getNuList(void) const;

	class InvalidInputException : public std::exception {
		public: virtual const char * what() const throw() {return _MAGENTA "Invalid Input" _END;} };

private:

	std::vector<std::string>	_input;

	std::vector<int>			_nuVector;
	std::list<int>				_nuList;

	PmergeMe(void);
	PmergeMe(PmergeMe const & src);
	PmergeMe & operator=(PmergeMe const & src);
};


# include "PmergeMe.tpp"

#endif