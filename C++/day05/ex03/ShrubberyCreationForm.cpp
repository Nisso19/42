#include "ShrubberyCreationForm.hpp"
# include <cstdlib>
// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shruberry default", 145, 137), _target("Default")
{
	std::cout << "Default Constructor called of ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "Copy Constructor called of ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("Shruberry", 145, 137), _target(target)
{
	std::cout << "Shruberry form was created" << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called of ShrubberyCreationForm" << std::endl;
}


// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	if (this != &assign)
	this->_target = assign._target;
	return *this;
}


void ShrubberyCreationForm::makeExecute() const
{
	std::string file;

	file = this->_target;
	file.append("_shruberry");
	std::cout << file << " has been created" << std::endl;
	std::ofstream stream(file.c_str());	
	
	stream	<< "      /\\\n"
			<< "     /\\*\\\n"    
			<< "    /\\O\\*\\\n"    
			<< "   /*/\\/\\/\\\n" 
			<< "  /\\0\\/\\*\\/\\\n" 
			<< " /\\*\\/\\*\\/\\/\\\n"
			<< "/\\O\\/\\/*/\\/O/\\\n"
			<< "      ||\n"
			<< "      ||\n"
			<< "      ||\n"
			<< "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾";

}
