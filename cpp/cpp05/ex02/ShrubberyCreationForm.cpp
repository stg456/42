/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:01:47 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/12 17:15:50 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string ShrubberyCreationForm): Form(ShrubberyCreationForm, 145, 137), _target("") {
	if (getGradeToSign() < 145 || getGradeToExecute() < 137)
		throw ShrubberyCreationForm::GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & copy): _target(copy._target) {*this = copy;}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm & rhs) {
	if (this == &rhs)
		return *this;
	this->getTarget() = rhs.getTarget();
	return *this;
}

const char * ShrubberyCreationForm::GradeTooLowException::what() const throw() {
	return ("Exception: Grade Too Low to sign or execute ShrubberyCreationForm");
}

std::string	ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	std::cout << getTarget() << " has create Shrubbery." << std::endl;
}