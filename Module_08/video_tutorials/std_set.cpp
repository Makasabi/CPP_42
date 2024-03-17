// std Set

/*
	set of UNIQUE objects - it can only have ONE of any particular type of item : they must ALL be UNIQUE
	elements of the set are to be indexed in orer
	A set does not have a front and a back - hence we replace the push_back with insert.

	when running the code : we see that we can only store a new number until we have numbers from 1 to 6.

	Elments of a set are ALWAYS at the same place in memory

*/

#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <deque>
#include <chrono>
#include <algorithm>

int main() 
{
	// lambda function to roll a die
	auto roll = []() {return rand() %6 + 1; };

	// create container
	std::set<int> container;

	// add 1 item
	container.insert(roll());
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
		container.insert(roll());
		auto tp2 = std::chrono::high_resolution_clock::now();
		durInsertTime = (tp2 - tp1);

	} while (getc(stdin));

	return 0;

}