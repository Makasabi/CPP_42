// Vector container

// container that is like an array but that can grow in size

/*
std::vector<int> a;

it is possible to do: a[3] = 6;

/!\ Pointer to an element of a vector that as grown may no longer be valid /!\

*/

#include <iostream>
#include <array>
#include <vector>
#include <chrono>

int main() 
{
	// lambda function to roll a die
	auto roll = []() {return rand() %6 + 1; };

	// create container
	std::vector<int> container;

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