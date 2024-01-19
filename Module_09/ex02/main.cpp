#include "PmergeMe.hpp"

bool trueDigit(std::string input) {

	for (std::string::iterator i = input.begin(); i != input.end(); ++i){
		if (!std::isdigit(*i))
			return false;
	}
	return true;
}

template <template <typename, typename> class container, typename T>
container<T, std::allocator<T> > containerBuilder(char **argv) {

	int									i = 1;
	container<T, std::allocator<T> >	sequence;

	while(argv[i])
	{
		if (trueDigit(argv[i]) == true){
			std::istringstream	ss(static_cast<std::string>(argv[i]));
			T					value;
			ss >> value;
			for(typename container<T, std::allocator<T> >::iterator i = sequence.begin(); i != sequence.end(); ++i) 
			{
				if (*i == value)
					throw std::invalid_argument("Duplicate Value");
			}
			sequence.push_back(value);
		}
		else
			throw std::invalid_argument("Invalid character");
		i++;
	}
	return sequence;
}



int main (int ac, char **av)
{
	if (ac < 2) {
		std::cout << _RED "Invalid argument count" _END << std::endl;
		return 1;
	}
	try {
		std::vector<int>	unsortedVec = containerBuilder<std::vector, int>(av);
		std::deque<int>		unsortedDeq = containerBuilder<std::deque, int>(av);

		PmergeMe<int, std::vector>	vec(unsortedVec);

		vec.SequencePrinter("Unsorted");
		std::vector<int>	sortedVec = vec.fordJohnson();

		// timer in - launch vector sorting - timer out
		// timer in - launch deque sorting - timer out
		// print sorted sequence
		// print time for vector
		// print time for deque
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}