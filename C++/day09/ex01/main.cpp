#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return(std::cout << "Usage: ./RPN mathematical_expression" << std::endl, 0);
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