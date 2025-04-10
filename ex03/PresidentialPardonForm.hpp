#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class PresidentialPardonForm : public AForm {
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
	protected:
		virtual void	action() const;
};

#endif