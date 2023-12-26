#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <iostream>

# include <vector>
# include <list>
# include <set>
# include <deque>
# include <stack>
# include <queue>

# include <algorithm>

template<typename T>
typename T::iterator easyfind(T & haystack, int needle)
{
	typename T::iterator end = haystack.end();
	typename T::iterator found = std::find(haystack.begin(), end, needle);

	if (found == end)
		throw(std::out_of_range("Int not found withing container data"));
	return (found);
}

// template<>
// int easyfind(std::stack<int>& haystack, int needle)
// {
// 	std::stack<int> tmp = haystack;

// 	while (!tmp.empty())
// 	{
// 		if (tmp.top() == needle)
// 			return tmp.top();

// 		tmp.pop();
// 	}

// 	throw std::out_of_range("Int not found within container data");
// 	return 100;
// }

// template<>
// int easyfind(std::priority_queue<int>& haystack, int needle)
// {
// 	std::priority_queue<int> tmp = haystack;

// 	while (!tmp.empty())
// 	{
// 		if (tmp.top() == needle)
// 			return tmp.top();

// 		tmp.pop();
// 	}

// 	throw std::out_of_range("Int not found within container data");
// 	return 100;
// }
// template<>
// int easyfind(std::queue<int>& haystack, int needle)
// {
// 	std::queue<int> tmp = haystack;

// 	while (!tmp.empty())
// 	{
// 		if (tmp.front() == needle)
// 			return tmp.front();

// 		tmp.pop();
// 	}

// 	throw std::out_of_range("Int not found within container data");
// 	return 100;
// }

#endif