#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Default ShrubberyCreation", 25, 5), _target("Default") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("ShrubberyCreation", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm constructor called with target: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other)
	{
		_target  = other._target;
		std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void	PresidentialPardonForm::action() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}