#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string.h>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_exec;
	public:
		AForm();
		AForm(const std::string& name, int gradeSign, int gradeExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string		getName() const;
		bool			getIsSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;

		void			beSigned(Bureaucrat const& object);
		virtual void	execute(Bureaucrat const & executor) const;

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

	protected:
		virtual void	action() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif