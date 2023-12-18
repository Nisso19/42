#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "GRADE -49:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	try
	{
		Bureaucrat Test1("Terry", -49);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "\n----------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "GRADE 450:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	try
	{
		Bureaucrat Test2("John", 450);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "\n----------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "GRADE 10:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	try
	{
		Bureaucrat Test3("Bill", 10);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

//////////////////////////////////////////////////
	Bureaucrat bob("Bob", 1);
	Bureaucrat terry(bob);
	try
	{
		bob.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << bob << std::endl;
	try
	{
		bob.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		bob.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << bob;
	std::cout << std::endl << std::endl;
}