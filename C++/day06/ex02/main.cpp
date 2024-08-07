#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int random_value;
	Base *res;
	random_value = rand() % 3;
	switch (random_value)
	{
		case 0: res = new A();
			break;
		case 1:	res = new B();
			break;
		default:res = new C();
	}
	return (res);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Type A" << std::endl;	
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Type B" << std::endl;
	else
		std::cout << "Type C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "Type A" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Pas A" << std::endl;
	}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "Type B" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Pas B" << std::endl;
	}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "Type C" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Pas C" << std::endl;
	}
}

int main(void)
{
	srand(time(0));
	Base *test = generate();
	identify(test);
	std::cout << std::endl;
	identify(*test);
	delete (test);
	return (0);
}