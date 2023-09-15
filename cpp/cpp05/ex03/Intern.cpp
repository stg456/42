/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:41:00 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/15 10:43:12 by stgerard         ###   ########.fr       */
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
	int i = 0;
	Form * (Intern::*makeForm[3]) (std::string target) = {&Intern::Shrub, &Intern::Robot, &Intern::Presid};
	std::string str[3] = {"shrubbery request", "robotomy request", "presidential pardon request"};
	if (formName == str[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*makeForm[i])(target);
	}
	else {
		std::cout << "the request " << formName << " do not exist." << std::endl;
		return NULL;
	}
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
