#include <vector>
#include <iostream>

std::vector<int> merge(std::vector<int> vectorOne, std::vector<int> vectorTwo) {

	std::vector<int> vectorThree;

	std::vector<int>::iterator i = vectorOne.begin();
	std::vector<int>::iterator j = vectorTwo.begin();

	while(i != vectorOne.end() && j != vectorTwo.end()) 
	{
		if (*i > *j) {
			vectorThree.push_back(*j);
			++j;
		}
		else {
			vectorThree.push_back(*i);
			++i;
		}
	}

	while (i != vectorOne.end()){
		vectorThree.push_back(*i);
		++i;
	}

	while (j != vectorTwo.end()){
		vectorThree.push_back(*j);
		++j;
	}

	return vectorThree;
}

std::vector<int> mergeSort(std::vector<int> toSort) {

	if (toSort.size() == 1)
		return toSort;

	std::vector<int> vectorOne;
	std::vector<int> vectorTwo;

	std::vector<int>::iterator half = toSort.begin() + toSort.size() / 2; 
	std::vector<int>::iterator i = toSort.begin();
	for (;i != half; ++i) {
		vectorOne.push_back(*i); }
	for (;i != toSort.end(); ++i) {
		vectorTwo.push_back(*i); }

	vectorOne = mergeSort(vectorOne);
	vectorTwo = mergeSort(vectorTwo);

	return merge(vectorOne, vectorTwo);
}

int main ()
{
	int table [] = {14, 7, 11, 13, 2, 12, 20, 9, 17, 4, 20, 18, 1, 10, 5, 6, 19, 16, 3, 15, 8};
	std::vector<int> toSort;

	for (int i = 0; i < 20; i++) {
		toSort.push_back(table[i]);
	}
	std::cout << "Unsorted: ";
	for (std::vector<int>::iterator i = toSort.begin(); i != toSort.end(); ++i)
	std::cout << *i << ", ";
	std::cout << std::endl;

	toSort = mergeSort(toSort);

	std::cout << "Sorted: ";
	for (std::vector<int>::iterator i = toSort.begin(); i != toSort.end(); ++i)
	std::cout << *i << ", ";
	std::cout << std::endl;
}