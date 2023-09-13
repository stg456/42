/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:09:11 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/13 15:50:15 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): _target("") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("", 25, 5), _target(target) {
	if (getGradeToSign() < 25 || getGradeToExecute() < 5)
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
	return ("Exception: Grade Too Low to sign or execute PresidentialPardonForm");
}

std::string	PresidentialPardonForm::getTarget() const {
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	std::cout << executor.getName() << " has create PresidentialPardonForm." << std::endl;
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}