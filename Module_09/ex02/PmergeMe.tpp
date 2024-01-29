#include "PmergeMe.hpp"

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe::binarySearch(int half, Container<T, Allocator> &chain, typename Container<T, Allocator>::iterator from, typename Container<T, Allocator>::iterator to)
{
	typename Container<T, Allocator>::iterator start = chain.begin() + half - 1;
	typename Container<T, Allocator>::iterator end = chain.end() - 1;
	typename Container<T, Allocator>::iterator mid;

	while (start != end)
	{
		mid = start + ((end - start) / half / 2) * half;
		if (*mid < *to)
			start = mid + half;
		else
			end = mid;
	}
	chain.insert(start - (half - 1), from, to + 1);
}

template <template <typename, typename> class Container, typename T, typename Allocator>
bool	PmergeMe::isSorted(Container<T, Allocator> &sequence)
{
	for (typename Container<T, Allocator>::iterator i = sequence.begin(); i != sequence.end() - 1; ++i){
		if (*i >= *(i + 1))
			return false;
	}
	return true;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe::swaper(typename Container<T, Allocator>::iterator bigger, typename Container<T, Allocator>::iterator smaller, int size)
{
	for (; size > 0; size--)
	{
		std::swap(*bigger, *smaller);
		bigger++;
		smaller++;
	}
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe::printer(Container<T, Allocator>  toPrint, std::string comment, int it)
{

	std::cout << _LAGOON << comment << ":\t" _END;
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

template <template <typename, typename> class Container, typename T, typename Allocator>
Container<T, Allocator> & PmergeMe::fordJohnson(Container<T, Allocator> &sequence, int it)
{
	if (sequence.size()/it == 0)
		return sequence;

	/********TESTS********/

	// std::cout << "*****************************" << "\nit = " << it << std::endl;
	// printer(sequence, "Unsorted pairs: ", it);

	/*********************/

	int		half = it / 2;

	for (typename Container<T, Allocator>::iterator i = sequence.begin(); i < sequence.end(); i += it)
	{
    if (std::distance(i, sequence.end()) < it)
			break;
		if (*(i + half - 1) > *(i + it - 1))
			swaper<Container, T, Allocator>(i, i + half, half);
	}

	/********TESTS********/

	// printer(sequence,"sorted pairs:", it);

	/*********************/

	fordJohnson(sequence, it*2);

	/********TESTS********/

	// std::cout << "\nit = " << it << std::endl;
	// std::cout << "half = " << half << std::endl;
	// printer(sequence,"Out of reccurssion:", it);

	/*********************/

	Container<T, Allocator>	main , pend, odd;

	/********TESTS********/

	// std::cout << "iterator to begining of odd : " <<  sequence.size() - (sequence.size() % it) << std::endl;

	/*********************/

	for (typename Container<T, Allocator>::iterator i = sequence.end() - (sequence.size() % it); i < sequence.end(); ++i)
		odd.push_back(*i);

	int	divider = 0;
	for (typename Container<T, Allocator>::iterator i = sequence.begin(); i < sequence.end() - (sequence.size() % it); i += half)
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

	/********TESTS********/

	// printer(main, "main:", half);
	// printer(pend, "pend:", half);
	// printer(odd, "odd:", half);

	/*********************/

	Container<T, Allocator> res = main;

	int index, js, prevjs = 0, n = 2;

	while(main.size() != sequence.size() - odd.size())
	{
		js = jacobsthalNumber(n);
		index = js;
		while (index > prevjs && index >= 1){
			if ((index - 1) * half >= static_cast<int>(pend.size()))
				index--;
			else {
				binarySearch(half, main, pend.begin()+((index -1) * half), pend.begin() + ((index -1) * half) + half -1);
				index--;
			}
		}
		prevjs = js;
		n++;
	}

	if (odd.size() < static_cast<size_t>(half) || odd[half -1] > main.back()){
		for (typename Container<T, Allocator>::iterator i = odd.begin(); i != odd.end(); ++i)
			main.push_back(*i);
	}
	else {
		binarySearch(half, main, odd.begin(), odd.begin() + half - 1);
		for (typename Container<T, Allocator>::iterator i = odd.begin()+ half; i != odd.end(); ++i)
			main.push_back(*i);
	}
	sequence = main;


	/********TESTS********/

	// printer(sequence, "Result:", 0);

	/*********************/
	return sequence;
}
