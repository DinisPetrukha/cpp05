#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string.h>
#include <exception>

class Form;

class Bureaucrat {
	private:
		const	std::string _name;
		int		_grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat(std::string name, int grade);
		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		void		signForm(Form& form);

		class GradeTooHighException: public std::exception {
			public:
				const char *what() const throw() {
					return "Grade too high!";
				}
		};

		class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw() {
					return "Grade too low!";
				}
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif