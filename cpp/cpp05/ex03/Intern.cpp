/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:41:00 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/14 16:23:54 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	this->_formName[0] = "shrubbery creation";
	this->_formName[1] = "robotomy request";
	this->_formName[2] = "presidential pardon";
	this->_form[0] = & Intern::makeShrubberyCreationForm;
	this->_form[1] = & Intern::makeRobotomyRequestForm;
	this->_form[2] = & Intern::makePresidentialPardonForm;
}

Intern::Intern(const Intern &copy) {
	*this = copy;
}

Intern & Intern::operator = (const Intern & rhs) {
	if (this == &rhs)
		return *this;
	return *this;
}

Intern::~Intern(void) {}

Form *		Intern::makeForm(std::string formName, std::string target) {
	for (int i = 0; i < 3; i++)
	{
		if (formName == this->_formName[i])
			return ((this->*_form[i])(target));
	}
	std::cout << "Form name not found" << std::endl;
	return NULL;
}

Form *		Intern::makeShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form *		Intern::makeRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

Form *		Intern::makePresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}
