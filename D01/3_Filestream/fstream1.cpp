#include <iostream>
#include <fstream>

int main ()
{
	std::ifstream	ifs("numbers");
	unsigned int	dst1;
	unsigned int	dst2;

	ifs >> dst1 >> dst2;
	std::cout << dst1 << " " << dst2 << std::endl;
	ifs.close();

	//-------------------------------------------//

	std::ofstream	ofs("test.out");

	ofs << "I like ponies a whole damn lot!" << std::endl;
	ofs.close();
}