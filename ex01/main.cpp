#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "\n--- TESTE 1: Criar Bureaucrats válidos ---\n";
	try {
		Bureaucrat b1("Alice", 1);
		Bureaucrat b2("Bob", 150);
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- TESTE 2: Criar Bureaucrat com grade inválido ---\n";
	try {
		Bureaucrat invalid("Invalid", 200); // Deve lançar exceção
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- TESTE 3: Incrementar e Decrementar Bureaucrat ---\n";
	try {
		Bureaucrat b("Charlie", 2);
		std::cout << b << std::endl;
		b.incrementGrade(); // Vai para 1
		std::cout << b << std::endl;
		b.incrementGrade(); // Deve lançar exceção (já está no grau máximo)
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- TESTE 4: Criar Forms válidos e inválidos ---\n";
	try {
		Form f1("FormA", 100, 50);
		Form f2("FormB", 1, 1);
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;

		Form f_invalid("BadForm", 0, 160); // Deve lançar exceção
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- TESTE 5: Bureaucrat a assinar Form (sucesso) ---\n";
	try {
		Bureaucrat b("Diana", 20);
		Form f("FormC", 30, 30);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- TESTE 6: Bureaucrat a assinar Form (falha) ---\n";
	try {
		Bureaucrat b("Edward", 100);
		Form f("FormD", 50, 50);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}