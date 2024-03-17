#include "Serializer.hpp"
#include "data.hpp"

int main(void) {

	Data*		data;
	uintptr_t	ptrData = 0;
	Data*		newData = NULL;

	data = new Data;
	data->i = 42;

	std::cout << "data:\t\t" << data <<std::endl;
	std::cout << "data->i:\t" << data->i <<std::endl;

	std::cout << "\nnewData:\t" << newData <<std::endl;

	std::cout << _GREYER << "Calling serialize on data" << _END << std::endl;

	ptrData = Serializer::serialize(data);

	std::cout << "ptrdata:\t" << ptrData <<std::endl;

	std::cout << _GREYER << "Calling deserialize on newData" << _END << std::endl;

	newData = Serializer::deserialize(ptrData);
	std::cout << "newData:\t" << newData <<std::endl;
	std::cout << "newData->i:\t" << newData->i <<std::endl;

	delete data;

}