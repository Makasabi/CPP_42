#include "sedString.hpp"

void		printError(std::string str){
	std::cout << _BOLD << _RED << "!!! Toodaloo !!!\n" << _END;
	std::cout << str << std::endl;
	return;
}

std::string	strReplace(std::string line, std::string s1, std::string s2) {

	std::size_t	found = 0;
	while((found = line.find(s1, found)) != std::string::npos) {

		line = line.substr(0, found) + s2 + line.substr(found + s1.size());
		found = found + s2.size();
	}
	return line;
}

int			sedString(std::string filename, std::string s1, std::string s2) {

	std::ifstream	infile(filename.c_str());

	if(((infile.rdstate() | std::ifstream::goodbit) != 0) || infile.peek() == EOF) {
		return printError("Invalid infile !"), 1;
	}
	std::string		file = filename + ".replace";
	std::ofstream	outfile(file.c_str());
	
	if((outfile.rdstate() | std::ifstream::goodbit) != 0)
		return printError("Invalid outfile !"), 1;

	std::stringstream	buffer;
	std::string			line;

	buffer << infile.rdbuf();
	line = buffer.str();
	outfile << strReplace(line, s1, s2);
	infile.close();
	outfile.close();
	return 0;
}
