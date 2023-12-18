#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);

		virtual void makeExecute() const;	
		
		
	private:
		std::string _target;
};

#endif