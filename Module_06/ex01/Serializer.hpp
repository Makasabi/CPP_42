#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>
# include "data.hpp"
# include "colors.hpp"

class Serializer {

public:
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(Serializer const &);

	Serializer operator=(Serializer const &);

};

#endif