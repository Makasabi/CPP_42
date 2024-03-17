// container std::list

// in memory storage : works like a linked list
// each node is pointing to the node that immediately precedes and follows it. 
// it is a bi-directionnal linked list.


// not very efficient when browsing through items. 
// no way of directly accessing an item. 


#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <chrono>
#include <algorithm>

int main() 
{
	// lambda function to roll a die
	auto roll = []() {return rand() %6 + 1; };

	// create container
	std::list<int> container;

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