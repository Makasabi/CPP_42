# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <exception>
# include <string>
# include <sstream>
# include <utility>
# include <algorithm>

void swaper(std::vector<int>::iterator bigger, std::vector<int>::iterator smaller, int size)
{
	for (; size > 0; size--)
	{
		std::swap(*bigger, *smaller);
		bigger++;
		smaller++;
	}

}

std::vector<int> & sortingPairs(std::vector<int> & test, int it)
{
	if (test.size()/it == 0)
		return test;

	std::cout << "\nit = " << it << ";\nUnsorted pairs:\t";
	for (size_t i = 0; i < test.size(); i++)
	{
		if (i % it == 0)
			std::cout << "| ";
		std::cout << test[i] << " ";
	}
	std::cout << std::endl;

	int		half = it /2;
	for (std::vector<int>::iterator i = test.begin(); i < test.end(); i += it)
	{
		if (i + it > test.end())
			break;
		if (*(i + half - 1) > *(i + it - 1))
			swaper(i, i + half, half);
	}
	std::cout << "sorted paired:\t";
	for (size_t i = 0; i < test.size(); i++)
	{
		if (i % it == 0)
			std::cout << "| ";
		std::cout << test[i] << " ";
	}
	std::cout << std::endl;

	test=sortingPairs(test, 2*it);

	std::vector<int>	main;
	std::vector<int>	pend;

	std::cout << "\nit = " << it << std::endl;
	// for (std::vector<int>::iterator i = test.begin(); i < test.end(); i += it)
	// {
	// 	for ()
	// }
	std::cout << "\nit = " << it << ";\nUnsorted pairs:\t";
	for (size_t i = 0; i < test.size(); i++)
	{
		if (i % it == 0)
			std::cout << "| ";
		std::cout << test[i] << " " ;
	}
	std::cout << std::endl;
	return test;
}

int main (void) {

	int vec[] = {8, 2, 9, 6, 5, 7, 1, 4, 3, 0};
	std::vector<int>	test(vec, vec+10);

	std::vector<int>	res = sortingPairs(test, 2);

}