#include "AForm.hpp"


AForm::AForm(): _name("Default AForm"),_gradeToSign(150), _gradeToExecute(150), _isSigned(false)
{
	std::cout << "A Default AForm has been created\n";
	return;
}

AForm::AForm(AForm const& Copy): _name(Copy._name), _gradeToSign(Copy._gradeToSign), _gradeToExecute(Copy._gradeToExecute), _isSigned(Copy._isSigned)
{
	std::cout << "AForm's copy constructor called" << std::endl;
}


AForm::AForm(std::string const & name, int gradeToSign, int gradeToExecute):
	_name(name),_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute),_isSigned(false)
{
	std::cout << "AForm " << this->_name << " has been created\n";
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw (AForm::GradeTooLowException());
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw (AForm::GradeTooHighException());
	return;
}

AForm::~AForm()
{
	std::cout << "AForm " << this->_name << " has been destroyed" << std::endl; 
}

AForm & AForm::operator=(AForm const & ref)
{
	if (this != &ref)
		this->_isSigned = ref._isSigned;
	return (*this);
}

std::string	const & AForm::getName(void ) const
{
	return (this->_name);
}

int	AForm::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute( void ) const
{
	return (this->_gradeToExecute);
}

bool	AForm::getIsSigned( void ) const
{
	return (this->_isSigned);
}

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if(this->_isSigned)
		throw(AForm::AlreadySignedException());
	if(bureaucrat.getGrade() > this->_gradeToSign)
		throw(AForm::GradeTooLowException());
	this->_isSigned = true;
	return;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_gradeToExecute)
		throw(AForm::GradeTooLowException());
	if (this->_isSigned == false)
		throw(AForm::NotSignedException());
	this->makeExecute();

}
const char *	AForm::GradeTooHighException::what(void) const throw()
{
	return("Grade too high for this AForm");
}

const char *	AForm::GradeTooLowException::what(void) const throw()
{
	return("Grade too low for this AForm");
}

const char *	AForm::AlreadySignedException::what(void) const throw()
{
	return("Your AForm is already signed");
}

const char *	AForm::NotSignedException::what(void) const throw()
{
	return("Your AForm is not signed");
}

std::ostream &	operator<<(std::ostream & o, AForm const & obj)
{
	o << obj.getName() << " need grade " << obj.getGradeToSign() << " to sign and grade "
		<< obj.getGradeToExecute() << " to execute, the AForm is ";
	if (obj.getIsSigned())
		std::cout << "signed";
	else
		std::cout << "not signed";
	return (o);
}