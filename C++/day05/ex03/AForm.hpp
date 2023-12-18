#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

	public:

			AForm(void);
			virtual ~AForm();
			AForm(AForm const & ref);
			AForm(std::string const & name, int gradeToSign, int gradeToExecute);

			AForm & operator=(AForm const & ref);


// getters
			std::string const & getName(void) const;
			int getGradeToSign (void) const;
			int getGradeToExecute (void) const;
			bool getIsSigned  (void) const;
			void beSigned(Bureaucrat const & bureaucrat);
			void execute(Bureaucrat const & executor) const;

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
		class NotSignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

	protected:
			virtual void makeExecute(void) const = 0;
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool		_isSigned;

};

std::ostream & operator<<( std::ostream & o, AForm const & obj);

#endif