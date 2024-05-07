#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): _name("Default"),  _grade(150)
{
	std::cout << "A default Bureaucrat has arrived\n";
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & ref) : _name(ref._name), _grade(ref._grade)
{
	std::cout << "Grade " << this->_grade << " Copy Bureaucrat " << this->_name << " has arrived" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade): _name(name), _grade(150)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		this->_grade = grade;
		std::cout << "Grade " << this->_grade << " Bureaucrat " << this->_name << " has arrived" << std::endl; 
	}
	return;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Grade " << this->_grade << " Bureaucrat " << this->_name << " has departed" << std::endl; 
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & ref)
{
	if (this != &ref)
	this->_grade = ref.getGrade();
	return (*this);
}

std::string	const & Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

void Bureaucrat::decrementGrade(void)
{
	if(this->_grade + 1 > 150)
		return(throw(Bureaucrat::GradeTooLowException()));
	else
	{
		this->_grade += 1;
		std::cout << this->_name << " has been demoted, he is now grade " <<  this->_grade << std::endl;
	}
	return;
}

void Bureaucrat::incrementGrade(void)
{
	if(this->_grade - 1 < 1)
		return(throw(Bureaucrat::GradeTooHighException()));
	else
	{
		this->_grade -= 1;
		std::cout << this->_name << " has been promoted, he is now grade " <<  this->_grade << std::endl;
	}
	return;

}

void	Bureaucrat::signForm(AForm & form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << "Form " << form.getName() << " has been signed" << std::endl;
	}
	catch(std::exception & e )
	{
		std::cout << "Form " << form.getName() << " can't be signed: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form.getName() << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << *this << " couldn't be executed because " << e.what() << std::endl;
	}



}

const char *	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return("You can't have a grade that high.");
}

const char *	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return("You can't have a grade that low.");
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & obj)
{
	o << "Bureaucrat " << obj.getName() << " has a grade " << obj.getGrade();
	return (o);
}