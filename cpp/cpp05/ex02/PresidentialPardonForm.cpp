/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:09:11 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/11 17:37:58 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): _target("") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): _target(target) {
	if (getGradeToSign() < 25 || getGradeToExecute() < 5)
		throw PresidentialPardonForm::GradeTooLowException();
	// if (getGradeToSign() >= 25 && getGradeToExecute() >= 5)
	// 	this->_target = target;
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
	return ("Exception: Grade Too Low");
}
