#include "easyfind.hpp"
#include "colors.hpp"

# include <cstdlib>
# include <time.h>

void	vectorTest(void)
{
	std::vector<int> vTest;

	srand(time(NULL));
	static int rnd = rand();

	int randSize = rnd % 50 + 1; 
	for (int i = 0; i < randSize; i++)
		vTest.push_back(rand() % 25 + 1);

	std::cout << _BOLD << "Vector list size:\t[" << randSize << "]" << _END << "\t\t\t";

	int	toFind = (rand() % 25) + 1;
	std::cout << _BOLD << _CYAN << "Looking for:\t[" << toFind << "]" << _END << std::endl;

	std::cout << _BOLD << "Vector elements: " << _END;
	for (std::vector<int>::iterator i = vTest.begin(); i != vTest.end(); ++i)
		std::cout << *i << ", ";
	std::cout << std::endl;

	try
	{
		int found = easyfind(vTest, toFind);
		std::cout << _EMMERALD <<"Found number [" << found << "]" << _END << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
}

void	dequeTest(void)
{
	std::deque<int> dTest;

	srand(time(NULL));
	static int rnd = rand();

	int randSize = rnd % 50 + 1; 
	for (int i = 0; i < randSize; i++)
		dTest.push_back(rand() % 25 + 1);

	std::cout << _BOLD << "Vector list size:\t[" << randSize << "]" << _END << "\t\t\t";

	int	toFind = (rand() % 25) + 2;
	std::cout << _BOLD << _CYAN << "Looking for:\t[" << toFind << "]" << _END << std::endl;

	std::cout << _BOLD << "Vector elements: " << _END;
	for (std::deque<int>::iterator i = dTest.begin(); i != dTest.end(); ++i)
		std::cout << *i << ", ";
	std::cout << std::endl;

	try
	{
		int found = easyfind(dTest, toFind);
		std::cout << _EMMERALD <<"Found number [" << found << "]" << _END << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
}

void	listTest(void)
{
	std::list<int> lTest;

	srand(time(NULL));
	static int rnd = rand();

	int randSize = rnd % 50 + 1; 
	for (int i = 0; i < randSize; i++)
		lTest.push_back(rand() % 25 + 1);

	std::cout << _BOLD << "Vector list size:\t[" << randSize << "]" << _END << "\t\t\t";

	int	toFind = (rand() % 25) + 3;
	std::cout << _BOLD << _CYAN << "Looking for:\t[" << toFind << "]" << _END << std::endl;

	std::cout << _BOLD << "Vector elements: " << _END;
	for (std::list<int>::iterator i = lTest.begin(); i != lTest.end(); ++i)
		std::cout << *i << ", ";
	std::cout << std::endl;

	try
	{
		int found = easyfind(lTest, toFind);
		std::cout << _EMMERALD <<"Found number [" << found << "]" << _END << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
}

void	stackTest(void)
{
	std::stack<int> sTest;

	srand(time(NULL));
	static int rnd = rand();

	int randSize = rnd % 50 + 1; 
	for (int i = 0; i < randSize; i++)
		sTest.push(rand() % 25 + 1);

	std::cout << _BOLD << "Vector list size:\t[" << randSize << "]" << _END << "\t\t\t";

	int	toFind = (rand() % 25) + 4;
	std::cout << _BOLD << _CYAN << "Looking for:\t[" << toFind << "]" << _END << std::endl;

	std::cout << _BOLD << "Vector elements: " << _END;
    std::stack<int> tmp = sTest;
    while (!tmp.empty()){
		std::cout << tmp.top() << ", ";
		tmp.pop();
	}
	std::cout << std::endl;

	try
	{
		int found = easyfind(sTest, toFind);
		std::cout << _EMMERALD <<"Found number [" << found << "]" << _END << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
}

void	queueTest(void)
{
	std::queue<int> qTest;

	srand(time(NULL));
	static int rnd = rand();

	int randSize = rnd % 50 + 1; 
	for (int i = 0; i < randSize; i++)
		qTest.push(rand() % 25 + 1);

	std::cout << _BOLD << "Vector list size:\t[" << randSize << "]" << _END << "\t\t\t";

	int	toFind = (rand() % 25) + 5;
	std::cout << _BOLD << _CYAN << "Looking for:\t[" << toFind << "]" << _END << std::endl;

	std::cout << _BOLD << "Vector elements: " << _END;
    std::queue<int> tmp = qTest;
    while (!tmp.empty()){
		std::cout << tmp.front() << ", ";
		tmp.pop();
	}
	std::cout << std::endl;

	try
	{
		int found = easyfind(qTest, toFind);
		std::cout << _EMMERALD <<"Found number [" << found << "]" << _END << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
}

void	priority_queueTest(void)
{
	std::priority_queue<int> pqTest;

	srand(time(NULL));
	static int rnd = rand();

	int randSize = rnd % 50 + 1; 
	for (int i = 0; i < randSize; i++)
		pqTest.push(rand() % 25 + 1);

	std::cout << _BOLD << "Vector list size:\t[" << randSize << "]" << _END << "\t\t\t";

	int	toFind = (rand() % 25) + 6;
	std::cout << _BOLD << _CYAN << "Looking for:\t[" << toFind << "]" << _END << std::endl;

	std::cout << _BOLD << "Vector elements: " << _END;
    std::priority_queue<int> tmp = pqTest;
    while (!tmp.empty()){
		std::cout << tmp.top() << ", ";
		tmp.pop();
	}
	std::cout << std::endl;

	try
	{
		int found = easyfind(pqTest, toFind);
		std::cout << _EMMERALD <<"Found number [" << found << "]" << _END << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
}

int main(void) {

	std::cout << _REV << _BOLD << "\t\t\t\t\t\t VECTOR \n" << _END << std::endl;
	vectorTest();
	std::cout << _REV << _BOLD << "\n\t\t\t\t\t\t DEQUE \n" << _END << std::endl;
	dequeTest();
	std::cout << _REV << _BOLD << "\n\t\t\t\t\t\t LIST \n" << _END << std::endl;
	listTest();
	std::cout << _REV << _BOLD << "\n\t\t\t\t\t\t STACK \n" << _END << std::endl;
	stackTest();
	std::cout << _REV << _BOLD << "\n\t\t\t\t\t\t QUEUE \n" << _END << std::endl;
	queueTest();
	std::cout << _REV << _BOLD << "\n\t\t\t\t\t\t QUEUE \n" << _END << std::endl;
	priority_queueTest();
	return 0;
}
