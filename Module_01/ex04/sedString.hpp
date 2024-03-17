#ifndef SEDSTRING_HPP
# define SEDSTRING_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <fstream>
# include <sstream>
# include "colors.hpp"

int		sedString(std::string infile, std::string s1, std::string s2);
void	printError(std::string str);

#endif