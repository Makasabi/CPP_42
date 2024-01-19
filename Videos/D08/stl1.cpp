#include <iostream>
#include <map>
#include <vector>
#include <list>

class IOperation {};


// Do not compile !
int main(void)
{
	std::list<int>						lst1; // linked list -> push back (put at the end of the list)
	std::map<std::string, IOperation>	map1; // hash table/ tablea associatif - not necessarily using a string as key : can be anything we'd like
	std::vector<int>					v1; // table that can contain anything.
	std::vector<int>					v2(42, 100); // a table of 42 entries that contain 100(int)

	lst1.push_back(1);
	lst1.push_back(17);
	lst1.push_back(42);

	map1["opA"] = new OperationA;
	map1["opB"] = new OperationB;

	std::list<int>::const_iterator		it;					// iterator on linked list = sort of pointer of contener
	std::list<int>::const_iterator		ite = lst1.end();	// iterator to the end of the linked list

	for (it = lst1.begin(); it != ite; ++it) // For loop to print content of each element of list
	{
		std::cout << *it << std::endl;
	}

	return 0;
}