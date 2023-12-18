#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		
		~RobotomyRequestForm();

		virtual void makeExecute() const;	
		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);
		
	private:
			std::string _target;	
};

#endif