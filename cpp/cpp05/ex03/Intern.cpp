/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:41:00 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/15 11:38:56 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

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
	std::string str[3] = {"shrubbery request", "robotomy request", "presidential pardon request"};
	Form * (Intern::*makeForm[3]) (std::string target) = {&Intern::Shrub, &Intern::Robot, &Intern::Presid};
	for (int i = 0; i < 3; i++) {
		if (formName == str[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*makeForm[i])(target);
		}
	}
		std::cout << "the request: " << formName << " do not exist." << std::endl;
		return NULL;
}

Form *		Intern::Shrub(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form *		Intern::Robot(std::string target) {
	return new RobotomyRequestForm(target);
}

Form *		Intern::Presid(std::string target) {
	return new PresidentialPardonForm(target);
}
