#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	// Data data = {.value = 10, .string = "test"};
	// uintptr_t temp;
	// Data *res;

	// temp = Serializer::serialize(&data);
	// res = Serializer::deserialize(temp);
	// if (&data == res)
	// {
	// 	std::cout << "ptr: " << &data << std::endl;
	// 	std::cout << "res: " << res << std::endl;
	// }
	// return (0);

	Data	data = {.value = 17, .string = "Test"};
	uintptr_t	serializedPointer = Serializer::serialize(&data);
	Data *		deserializedPointer = Serializer::deserialize(serializedPointer);

	std::cout << "Original " << data << std::endl;
	std::cout << "Pointer as an int " << serializedPointer << std::endl << std::endl;
	std::cout << "Deserialized " << *deserializedPointer << std::endl;
	return (0);
}