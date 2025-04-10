#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& ) {
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern&) {
	std::cout << "Intern assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string target)
{
	typedef AForm* (Intern::*FormCreator)(const std::string& target);

	struct FormOption{
		std::string name;
		FormCreator create;
	};

	FormOption formnames[3];

	formnames[0].name = "shrubbery creation";
	formnames[0].create = &Intern::makeShrubbery;

	formnames[1].name = "robotomy request";
	formnames[1].create = &Intern::makeRobotomy;

	formnames[2].name = "presidential pardon";
	formnames[2].create = &Intern::makePresidential;

	for (int i = 0; i < 3; i++)
	{
		if (formnames[i].name == name)
		{
			std::cout << "Intenr creates" << name << "." << std::endl;
			return (this->*formnames[i].create)(target);
		}
	}

	std::cerr << "Error: Unknown form name '" << name << "'." << std::endl;
	return NULL;
}