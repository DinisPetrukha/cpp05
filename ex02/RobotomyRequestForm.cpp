#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Default ShrubberyCreation", 72, 45), _target("Default") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("ShrubberyCreation", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm constructor called with target: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
	{
		_target  = other._target;
		std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void	RobotomyRequestForm::action() const {
	std::cout << "* drilling noizes: PITONCHIK BIM BIM BAM BAM BZZZ KRPAU" << std::endl;
	if (rand() % 2 == 0)
		std::cout << _target << "has been robotomized successfully " << std::endl;
	else
		std::cout << "Robotomy on " << _target << "failed." << std::endl;
}