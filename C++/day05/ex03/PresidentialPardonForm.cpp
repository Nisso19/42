
#include "PresidentialPardonForm.hpp"
# include <cstdlib>

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential default", 25, 5), _target("Default")
{
	std::cout << "Default Constructor called of PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "Copy Constructor called of PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("Presidential", 25, 5), _target(target)
{
	std::cout << "Presidential form was created" << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called of PresidentialPardonForm" << std::endl;
}


// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	if (this != &assign)
	this->_target = assign._target;
	return *this;
}

void PresidentialPardonForm::makeExecute() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox\n";
}

