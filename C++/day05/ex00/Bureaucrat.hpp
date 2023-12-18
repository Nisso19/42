#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{

	public:

			Bureaucrat(void);
			Bureaucrat(Bureaucrat const & ref);
			Bureaucrat(std::string const & name, int grade);
			~Bureaucrat(void);

			Bureaucrat & operator=(Bureaucrat const & ref);


// getters
			std::string const & getName(void) const;
			int getGrade (void) const;
// increment decrement
			void incrementGrade(void);
			void decrementGrade(void);


		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		const std::string _name;
		int _grade;
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & obj);

#endif