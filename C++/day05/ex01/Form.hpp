#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

			Form(void);
			Form(Form const & ref);
			Form(std::string const & name, int gradeToSign, int gradeToExecute);
			~Form(void);

			Form & operator=(Form const & ref);


// getters
			std::string const & getName(void) const;
			int getGradeToSign (void) const;
			int getGradeToExecute (void) const;
			bool getIsSigned  (void) const;

		void	beSigned(Bureaucrat const & bureaucrat);

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
		class AlreadySignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};
	
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool		_isSigned;

};

std::ostream & operator<<( std::ostream & o, Form const & obj);

#endif