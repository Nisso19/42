#include "Intern.hpp"


int main(void)
{
	Intern someRandomIntern;
	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("ShrubberyCreation", "Christmas");
		Bureaucrat pb("Pam Beesly", 137);
		pb.signForm(*rrf);
		pb.executeForm(*rrf);
		std::cout << std::endl;
		delete rrf;
	}
	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("RobotomyRequest", "Bender");
		Bureaucrat jh("Jim Halpert", 45);
		jh.signForm(*rrf);
		jh.executeForm(*rrf);
		std::cout << std::endl;
		delete rrf;
	}
	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("PresidentialPardon", "Dwight Shrut");
		Bureaucrat ms;
		ms.signForm(*rrf);
		ms.executeForm(*rrf);
		std::cout << std::endl;
		delete rrf;
	}
	{
		AForm* rrf;
		try
		{
			rrf = someRandomIntern.makeForm("Presidential", "Dwight Shrut");
			Bureaucrat ms;
			ms.signForm(*rrf);
			ms.executeForm(*rrf);
			std::cout << std::endl;
			delete rrf;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}