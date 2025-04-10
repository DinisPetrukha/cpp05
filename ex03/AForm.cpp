#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Default"), _signed(false), _grade_sign(150), _grade_exec(150){
	std::cout << "AForm default created!" << std::endl;
}

AForm::AForm(const std::string& name, int gradeSign, int gradeExec)
	: _name(name), _signed(false), _grade_sign(gradeSign), _grade_exec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	std::cout << "AForm " << _name << " created!" << std::endl;
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signed(other._signed), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec) {
	std::cout << "AForm copied!" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		std::cout << "AForm assigned!" << std::endl;
		this->_signed = other._signed;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << _name + " form has been destroyed" << std::endl;
}

std::string	AForm::getName() const
{
	return	_name;
}

bool	AForm::getIsSigned() const
{
	return _signed;
}

int	AForm::getGradeToSign() const
{
	return _grade_sign;
}

int	AForm::getGradeToExecute() const
{
	return _grade_exec;
}

void	AForm::beSigned(Bureaucrat const& object)
{
	if (object.getGrade() > getGradeToSign())
		throw AForm::GradeTooLowException();
	_signed = true;
}

std::ostream&	operator<<(std::ostream& os, const AForm& form) {
	os << form.getName()
		<< ", signed: " << form.getIsSigned()
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute();
	return os;
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (!this->getIsSigned())
		throw std::runtime_error("Form not signed!");
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();

	this->action();
}
