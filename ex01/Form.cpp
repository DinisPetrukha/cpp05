#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("Default"), _signed(false), _grade_sign(150), _grade_exec(150){
	std::cout << "Form default created!" << std::endl;
}

Form::Form(const std::string& name, int gradeSign, int gradeExec)
	: _name(name), _signed(false), _grade_sign(gradeSign), _grade_exec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	std::cout << "Form " << _name << " created!" << std::endl;
}

Form::Form(const Form& other)
	: _name(other._name), _signed(other._signed), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec) {
	std::cout << "Form copied!" << std::endl;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		std::cout << "Form assigned!" << std::endl;
		this->_signed = other._signed;
	}
	return *this;
}

Form::~Form()
{
	std::cout << _name + " form has been destroyed" << std::endl;
}

std::string	Form::getName() const
{
	return	_name;
}

bool	Form::getIsSigned() const
{
	return _signed;
}

int	Form::getGradeToSign() const
{
	return _grade_sign;
}

int	Form::getGradeToExecute() const
{
	return _grade_exec;
}

void	Form::beSigned(Bureaucrat const& object)
{
	if (object.getGrade() > getGradeToSign())
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << form.getName()
		<< ", signed: " << form.getIsSigned()
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute();
	return os;
}
