/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:02:17 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/11 17:41:05 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): _target("") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): _target(target) {
	if (getGradeToSign() < 72 || getGradeToExecute() < 45)
		throw RobotomyRequestForm::GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & copy): _target(copy._target) {*this = copy;}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm & rhs) {
	if (this == &rhs)
		return *this;
	this->getTarget() = rhs.getTarget();
	return *this;
}

const char * RobotomyRequestForm::GradeTooLowException::what() const throw() {
	return ("Exception: Grade Too Low");
}