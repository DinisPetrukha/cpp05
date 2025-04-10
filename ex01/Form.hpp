#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string.h>
#include <exception>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_exec;
	public:
		Form();
		Form(const std::string& name, int gradeSign, int gradeExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string	getName() const;
		bool				getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void	beSigned(Bureaucrat const& object);

		class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw() {
					return "Grade too low to sign the form!";
				}
		};
		class GradeTooHighException: public std::exception {
			public:
				const char *what() const throw() {
					return "Grade too high to sign the form!";
				}
		};
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif