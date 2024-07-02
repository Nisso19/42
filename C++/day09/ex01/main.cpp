#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Usage: ./RPN mathematical_expression" << std::endl;
	std::string input(argv[1]);	
	try
	{
		RPN test(input);
		std::cout << test.getResult() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}