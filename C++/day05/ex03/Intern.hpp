#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		AForm* makeShrubberyCreation(std::string const& target);
		AForm* makeRobotomyRequest(std::string const& target);
		AForm* makePresidentialPardon(std::string const& target);
		AForm* makeForm(std::string const& formType, std::string const& targetForm);

		// Destructor
		~Intern();
		
		// Operators
		Intern & operator=(const Intern &assign);
		class FormDontExistException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
};

#endif