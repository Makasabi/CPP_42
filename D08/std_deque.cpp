// hybrid structure : sort of a linked list of array.

/*
	Data structure that has the insertion speed of a list but the indexable speed of a vector.
	sort of a linked list of arrays.

	When adding a new item to the deque, it must make a decision about adding it to a free space in an array, or adding a new block (such as a node) at the end of the list, then adding the new piece of data to the first available spot.
	No requirement to copy the content of the deque when adding new data.

	A deque contains an index that does the required calculations to convert a direct access index to the correct location required
	which means that the deque container already has quite a large memory overhead from the start as it requires some setup.
	
*/

#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <chrono>
#include <algorithm>

int roll() 
{
	return rand() %6 + 1; 
}

int main() 
{
	// lambda function to roll a die
	// auto roll = []() {};

	// create container
	std::deque<int> container;

	// add 1 item
	container.push_back(roll());
	const int* pAddressOfOriginlItemZero = &(* container.begin());

	std::chrono::duration<double> durInsertTime(0);

	do
	{
		//get address of first item
		const int * pAddressofItemZero = &(*container.begin());

		std::cout << "Contains " << container.size() << " element, took "<<
			std::chrono::duration_cast<std::chrono::microseconds>(durInsertTime).count() << "us" << std::endl;
		
		for (const auto& i : container)
		{
			const int * pAddressofItemX = &i;
			int pItemOffset = pAddressofItemX - pAddressofItemZero;
			int pItemOffsetOriginal = pAddressofItemX - pAddressOfOriginlItemZero;
			std::cout << "Offset From Original: " << pItemOffsetOriginal << "	Offset From Zero: " << pItemOffset << "	: Content: " << i << std::endl;
		}

		auto tp1 = std::chrono::high_resolution_clock::now();
		container.push_back(roll());
		auto tp2 = std::chrono::high_resolution_clock::now();
		durInsertTime = (tp2 - tp1);

	} while (getc(stdin));

	return 0;

}