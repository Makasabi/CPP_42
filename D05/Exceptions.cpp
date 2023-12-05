#include <stdexcept>

void test1()
{
	try
	{
		//Do some stuff here
		if (/*there's an error*/)
		{
			throw std::exception();
		}
		else
		{
			//do something else
		}
		
	}
	catch(const std::exception& e)
	{
		//handle error here
	}
	
}

void test2(){
	//Do some stuff here
	if (/*there's an error*/)
	{
		throw std::exception();
	}
	else
	{
		//Do some more stuff
	}
}

void test3()
{
	try
	{
		test2();
	}
	catch(std::exception& e)
	{
		//handle error
	}
	
}

void test4()
{
	class PEBKACException : public std::exception
	{
		public :
		virtual const char *what() const throw()
		{
			return ("problem exists between keyboard and chair");
		}
	};

	try
	{
		{
			test3();
		}
	}
	catch(PEBKACException& e)
	{
		//Handle the fact that the user is an idiot
	}
	catch (std::exception& e)
	{
		//handle other exception that are like std::exception
	}
	
}