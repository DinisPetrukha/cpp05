#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <ctime>


int main() {
	Intern someRandomIntern;

	std::cout << "\n--- Test: Create ShrubberyCreationForm ---" << std::endl;
	AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Garden");
	if (shrub) {
		std::cout << *shrub << std::endl;
		delete shrub;
	}

	std::cout << "\n--- Test: Create RobotomyRequestForm ---" << std::endl;
	AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
	if (robotomy) {
		std::cout << *robotomy << std::endl;
		delete robotomy;
	}

	std::cout << "\n--- Test: Create PresidentialPardonForm ---" << std::endl;
	AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
	if (pardon) {
		std::cout << *pardon << std::endl;
		delete pardon;
	}

	std::cout << "\n--- Test: Invalid Form ---" << std::endl;
	AForm* invalid = someRandomIntern.makeForm("coffee request", "Intern");
	if (invalid) {
		delete invalid;
	}

	std::cout << "\n--- Done! ---" << std::endl;

	return 0;
}
