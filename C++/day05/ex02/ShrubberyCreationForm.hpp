#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include <iostream>
# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm:  public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		
		~ShrubberyCreationForm();
		virtual void makeExecute() const;	
		
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);
		
	private:
			std::string _target;
};

#endif