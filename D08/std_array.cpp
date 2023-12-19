//// Array Containers - CPP 11 /!\ 
/*
	array
	Begin				End
	[][][][][][][][][][][]
				↖️ iterator
*/

#include <iostream>
#include <array>

int main() 
{
	std::array<int, 10> b; // syntax for container array (from stl)

	// traditional way of initialising values of the arrays
	for (int i = 0; i < 10; i++)
	{
		b[i] = something();
	}
	// /!\ very inflexible and not very secure /!\

	// let's optimize it by interogating it about its own size
	for (int i = 0; i < b.size(); i++)
	{
		b[i] = something();
	}

	// let's use iterators associated with our array container
	// for (std::array<int, 10>::iterator i = b.begin(); i != b.end(); ++i)
	for (auto i = b.begin(); i != b.end(); ++i)
	{
		*i = something(); // an iterator is a bit like a pointer
	}

	// ranged 'for loop' that will automatically iterate through every items of the container
	for (auto& i : b)
	{
		*i = something();
	}

	// use of algorithms to to the exact SAME: 

	std::fill(b.begin(), b.end(), something());

	b = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
}

