#pragma once

# include <iostream>
# include <string>
# include <sstream>
# include <list>
# include <vector>
# include <exception>
# include <utility>

# include "colors.hpp"

class PmergeMe {

public: 

	PmergeMe(char **argv);
	~PmergeMe(void);

	static bool trueDigit(std::string input);

template<typename T>
void	printSequence(const T& container) const;

template<typename Type>
std::vector<Type>	sort(std::vector<Type> container);

	// void sortlist(void);

	std::vector<int>			getNuVector(void) const;
	std::vector<std::string>	getInput(void) const;
	std::list<int>				getNuList(void) const;

	class InvalidInputException : public std::exception {
		public: virtual const char * what() const throw() {return _MAGENTA "Invalid Input" _END;} };

private:

	std::vector<std::string>	_input;

	std::vector<int>			_nuVector;
	std::list<int>				_nuList;

	size_t						_inc;
	bool						_odd;

	PmergeMe(void);
	PmergeMe(PmergeMe const & src);
	PmergeMe & operator=(PmergeMe const & src);


};


#include "PmergeMe.tpp"