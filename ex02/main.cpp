#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(std::time(NULL));  // Seed para rand()

	try {
		Bureaucrat bob("Bob", 100);
		ShrubberyCreationForm shrub("Home");

		std::cout << "\n--- Form Info ---\n" << shrub << "\n";

		std::cout << "\n--- Bob tries to execute before signing ---\n";
		try {
			shrub.execute(bob);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\n--- Bob signs the form ---\n";
		bob.signForm(shrub);

		std::cout << "\n--- Bob tries to execute again ---\n";
		shrub.execute(bob);

		std::cout << "\n--- Testing RobotomyRequestForm ---\n";
		RobotomyRequestForm robo1("TargetBot");
		RobotomyRequestForm robo2(robo1);  // Copy constructor
		RobotomyRequestForm robo3;
		robo3 = robo1; // Assignment

		Bureaucrat alice("Alice", 40);  // Grade high enough

		std::cout << "\n--- Alice signs robo1 ---\n";
		alice.signForm(robo1);

		std::cout << "\n--- Alice executes robo1 (should robotomize) ---\n";
		robo1.execute(alice);

		std::cout << "\n--- Alice executes robo1 again (50% chance again) ---\n";
		robo1.execute(alice);

		std::cout << "\n--- Testing PresidentialPardonForm ---\n";
		PresidentialPardonForm pardon1("CriminalX");
		PresidentialPardonForm pardon2(pardon1);  // Copy constructor
		PresidentialPardonForm pardon3;
		pardon3 = pardon1;  // Assignment operator

		Bureaucrat zaphod("Zaphod", 1);  // Grade high enough for everything

		std::cout << "\n--- Zaphod tries to execute before signing ---\n";
		try {
			pardon1.execute(zaphod);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\n--- Zaphod signs pardon1 ---\n";
		zaphod.signForm(pardon1);

		std::cout << "\n--- Zaphod executes pardon1 ---\n";
		pardon1.execute(zaphod);

		std::cout << "\n--- Done! ---\n";

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
