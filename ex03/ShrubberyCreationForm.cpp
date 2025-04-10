#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Default ShrubberyCreation", 145, 137), _target("Default") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreation", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor called with target: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
	{
		_target  = other._target;
		std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	ShrubberyCreationForm::action() const {
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open()) {
		std::cerr << "Error: couldn't create file." << std::endl;
		return;
	}

	file	<< "       _-_\n"
			<< "    /~~   ~~\\\n"
			<< " /~~         ~~\\\n"
			<< "{               }\n"
			<< " \\  _-     -_  /\n"
			<< "   ~  \\\\ //  ~\n"
			<< "_- -   | | _- _\n"
			<< "  _ -  | |   -_\n"
			<< "      // \\\\\n";

	file.close();
}