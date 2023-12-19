/*
	maps 

	Fundamentaly different from the rest of containers
	a map requires 2 types specified as part of its template : typically keys and values pairs.

	hence the first type specified will be the type of the key part of the map
	while the second will be if its value.

	the map will add new elements to the top of the list - much like a stack.
*/
#include <iostream>
#include <unordered_map> // only in CPP 11
#include <algorithm>
#include <string>

int main() 
{

	std::unordered_map<std::string, int> container;

	container["one"] = 1;
	container["two"] = 2;
	container["three"] = 3;
	container["four"] = 4;
	container["five"] = 5;
	container["six"] = 6;

	// for (auto& i : container)  c++11
	for (std::unordered_map<std::string, int>::iterator i = container.begin(); i != container.end(); ++i)
	{
		std::cout << i->first << " = " << i->second << std::endl;
	}

	return 0;

}