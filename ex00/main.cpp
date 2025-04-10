#include "Bureaucrat.hpp"

int main() {
	std::cout << "=== Criar Bureaucrat válido ===" << std::endl;
	try {
		Bureaucrat b1("Maria", 42);
		std::cout << b1 << std::endl;

		std::cout << "Incrementar Maria:" << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;

		std::cout << "Decrementar Maria:" << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Erro: " << e.what() << std::endl;
	}

	std::cout << "\n=== Criar Bureaucrat com grade demasiado alta ===" << std::endl;
	try {
		Bureaucrat b2("João", 0); // Deve lançar exceção
		std::cout << b2 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Erro: " << e.what() << std::endl;
	}

	std::cout << "\n=== Criar Bureaucrat com grade demasiado baixa ===" << std::endl;
	try {
		Bureaucrat b3("Ana", 151); // Deve lançar exceção
		std::cout << b3 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Erro: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testar incremento acima de 1 ===" << std::endl;
	try {
		Bureaucrat b4("Carlos", 1);
		std::cout << b4 << std::endl;
		b4.incrementGrade(); // Deve lançar exceção
	}
	catch (const std::exception& e) {
		std::cerr << "Erro: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testar decremento abaixo de 150 ===" << std::endl;
	try {
		Bureaucrat b5("Rita", 150);
		std::cout << b5 << std::endl;
		b5.decrementGrade(); // Deve lançar exceção
	}
	catch (const std::exception& e) {
		std::cerr << "Erro: " << e.what() << std::endl;
	}

	return 0;
}
