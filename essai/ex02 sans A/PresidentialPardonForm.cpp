/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:09:11 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/20 14:57:21 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): _target("PresidentialPardonForm") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form(target, 25, 5), _target(target) {
	if (getGradeToSign() > 25 || getGradeToExecute() > 5)
		throw PresidentialPardonForm::GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & copy): _target(copy._target) {*this = copy;}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm & rhs) {
	if (this == &rhs)
		return *this;
	this->getTarget() = rhs.getTarget();
	return *this;
}

const char * PresidentialPardonForm::GradeTooLowException::what() const throw() {
	return ("Exception: Grade Too Low to execute PresidentialPardonForm");
}

std::string	PresidentialPardonForm::getTarget() const {
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > 5)
		throw PresidentialPardonForm::GradeTooLowException();
	if (executor.getGrade() <= 5) {
		std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
	}
}