#include "Intern.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "Default Constructor called of Intern" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "Copy Constructor called of Intern" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "Destructor called of Intern" << std::endl;
}

AForm* Intern::makeShrubberyCreation(std::string const& target)
{
	return (new ShrubberyCreationForm(target));

}
AForm* Intern::makeRobotomyRequest(std::string const& target)
{
	return (new RobotomyRequestForm(target));

}
AForm* Intern::makePresidentialPardon(std::string const& target)
{
	return (new PresidentialPardonForm(target));

}

AForm* Intern::makeForm(std::string const& formType, std::string const& targetForm)
{
	std::string tabType[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	AForm* (Intern::*form_ptrs[3])(std::string const&) = {&Intern::makeShrubberyCreation, &Intern::makeRobotomyRequest, &Intern::makePresidentialPardon};
	int i = 0;
	for (i = 0; i < 3; ++i)
	{
		if (formType == tabType[i])
			return ((this->*form_ptrs[i])(targetForm));
	}
	if (i == 3)
		throw (Intern::FormDontExistException());
	return (NULL);

}

// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

const char *Intern::FormDontExistException::what(void) const throw()
{
	return("Unknown type form");
}