#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy default", 72, 45), _target("Default")
{
	std::cout << "Default Constructor robotomy called of RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "Copy Constructor called of RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("Robotomy", 72, 45), _target(target)
{
	std::cout << "Robotomy form was created" << std::endl;
}


// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called of RobotomyRequestForm" << std::endl;
}


// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
		if (this != &assign)
	this->_target = assign._target;
	return (*this);
}


void RobotomyRequestForm::makeExecute() const
{
	if (std::rand() % 2)
	{
		std::cout << "bzzzz bzzz bzbzzzz... ";
		std::cout << this->_target << " has been lobotomized\n";
	}
	else
		std::cout << this->_target << " resisted lobotomization\n";
}
