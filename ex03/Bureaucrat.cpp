#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){
	std::cout << "Default bureaucrat created!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copied!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		std::cout << "Bureaucrat assigned!" << std::endl;
		this->_grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << _name + " bureaucrat has been destroyed" << std::endl;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	std::cout << _name << " bureaucrat created!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

void	Bureaucrat::signForm(AForm &form)
{
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << this->getName() << " could't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}