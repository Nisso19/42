#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat dw("Dwight Shrut", 150);
	Bureaucrat pb("Pam Beesly", 137);
	ShrubberyCreationForm f1("Christmas");
	pb.signForm(f1);
	dw.executeForm(f1);
	pb.executeForm(f1);
	std::cout << std::endl;

	RobotomyRequestForm f2("Dwight Shrut");
	RobotomyRequestForm f3("Jim Halpert");
	Bureaucrat jh("Jim Halpert", 45);
	jh.signForm(f2);
	jh.signForm(f3);
	jh.executeForm(f2);
	dw.executeForm(f3);
	jh.executeForm(f3);
	std::cout << std::endl;
	
	Bureaucrat ms;
	PresidentialPardonForm f4("Dwight Shrut");
	ms.signForm(f4);
	ms.executeForm(f4);
	jh.executeForm(f4);
	std::cout << std::endl;

	return (0);
}