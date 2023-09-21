/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:02:17 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/21 12:09:43 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 25, 5), _target("Bender") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {
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
	return ("Exception: Grade Too Low to execute RobotomyRequestForm");
}

std::string	RobotomyRequestForm::getTarget() const {
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > 45)
		throw RobotomyRequestForm::GradeTooLowException();
	std::cout << "drill noises" << std::endl;
	std::srand(std::time(0)); // la generation du code aleatoire sur la graine fonction du temps
	int i = std::rand();
	{
		if (i % 2 == 0)
			std::cout << executor.getName() << " has been robotomized." << std::endl;
		else
			std::cout << executor.getName() << " has not been robotomized." << std::endl;
	}
}