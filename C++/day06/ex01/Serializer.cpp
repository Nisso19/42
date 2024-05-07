#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data * ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

std::ostream &	operator<<(std::ostream & os, const Data & obj)
{
	os << "Data structure [" << &obj << "]" << "\nvalue: " << obj.value << "\nstring: " << obj.string << std::endl;
	return (os);
}