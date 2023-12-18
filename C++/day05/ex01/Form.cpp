#include "Form.hpp"


Form::Form(): _name("Default form"),_gradeToSign(150), _gradeToExecute(150), _isSigned(false)
{
	std::cout << "A Default Form has been created\n";
	return;
}

Form::Form(Form const& Copy): _name(Copy._name), _gradeToSign(Copy._gradeToSign), _gradeToExecute(Copy._gradeToExecute), _isSigned(Copy._isSigned)
{
	std::cout << "Form's copy constructor called" << std::endl;
}

Form::Form(std::string const & name, int gradeToSign, int gradeToExecute):
	_name(name),_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute),_isSigned(false)
{
	std::cout << "Form " << this->_name << " has been created\n";
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw (Form::GradeTooLowException());
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw (Form::GradeTooHighException());
	return;
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " has been destroyed" << std::endl; 
}

Form & Form::operator=(Form const & ref)
{
	if (this != &ref)
		this->_isSigned = ref._isSigned;
	return (*this);
}

std::string	const & Form::getName(void ) const
{
	return (this->_name);
}

int	Form::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute( void ) const
{
	return (this->_gradeToExecute);
}

bool	Form::getIsSigned( void ) const
{
	return (this->_isSigned);
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if(this->_isSigned)
		throw(Form::AlreadySignedException());
	if(bureaucrat.getGrade() > this->_gradeToSign)
		throw(Form::GradeTooLowException());
	this->_isSigned = true;
	return;
}

const char *	Form::GradeTooHighException::what(void) const throw()
{
	return("Grade too high for this form");
}

const char *	Form::GradeTooLowException::what(void) const throw()
{
	return("Grade too low for this form");
}

const char *	Form::AlreadySignedException::what(void) const throw()
{
	return("Your form is already signed");
}

std::ostream &	operator<<(std::ostream & o, Form const & obj)
{
	o << obj.getName() << " need grade " << obj.getGradeToSign() << " to sign and grade "
		<< obj.getGradeToExecute() << " to execute, the form is ";
	if (obj.getIsSigned())
		std::cout << "signed";
	else
		std::cout << "not signed";
	return (o);
}