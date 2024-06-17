#include "Serializer.hpp"

int main()
{
	std::cout << "====TESTS BEGIN====\n\n";

	Data data;

	data.name = "Data Name";
	data.age = 18;

	std::cout << "data name : " << data.name << std::endl;
	std::cout << "data age : " << data.age << std::endl;

	std::cout << "\n---Converting data pointer to uintptr---\n\n";


	Serializer Serializer;

	uintptr_t unPtr = Serializer.serialize(&data);

	std::cout << "unPtr value : " << unPtr << std::endl;

	std::cout << "\n---should see the same name and age---\n\n";

	Data* newDataPtr = Serializer.deserialize(unPtr);

	std::cout << "New data pointer name : " << newDataPtr->name << std::endl;
	std::cout << "New data pointer age : " << newDataPtr->age << std::endl;

	std::cout << "\n\n====TESTS END====" << std::endl;

	return 0;
}