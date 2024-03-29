/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:41:00 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/21 11:45:24 by stgerard         ###   ########.fr       */
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

AForm *		Intern::makeForm(std::string formName, std::string target) {
	std::string str[3] = {"shrubbery request", "robotomy request", "presidential pardon request"};
	AForm * (Intern::*makeForm[3]) (std::string target) = {&Intern::Shrub, &Intern::Robot, &Intern::Presid};
	for (int i = 0; i < 3; i++) {
		if (formName == str[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*makeForm[i])(target);
		}
	}
		std::cout << "the request: " << formName << " do not exist." << std::endl;
		return NULL;
}

AForm *		Intern::Shrub(std::string target) {
	AForm* Shrub = new ShrubberyCreationForm(target);
	return (Shrub);
}

AForm *		Intern::Robot(std::string target) {
	AForm* Robot = new RobotomyRequestForm(target);
	return (Robot);
}

AForm *		Intern::Presid(std::string target) {
	AForm* Presid = new PresidentialPardonForm(target);
	return (Presid);
}
