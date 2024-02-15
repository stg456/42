/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:01:47 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/26 08:37:46 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 0, 25, 5), _target("Bender") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 0, 145, 137), _target(target) {
	this->_target = target;
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
	return ("Exception: Grade Too Low to execute ShrubberyCreationForm");
}

std::string	ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > 137)
		throw ShrubberyCreationForm::GradeTooLowException();
	else {
		std::cout << executor.getName() << " has create Shrubbery." << std::endl;
		std::ofstream out;
		if (!out)
		{
			std::cerr << "Error: cannot create file." << std::endl;
			return ;
		}
		out.open(this->getName(), std::ios::out);
		out << "  o__o___o__o " << std::endl;
		out << "    o/_/_/o   " << std::endl;
		out << "       ||     " << std::endl;
		out << "       ||     " << std::endl;
		out << "	  /||+    " << std::endl;
		out << "              " << std::endl;
		out << "  o__o___o__o " << std::endl;
		out << "    o/_/_/o   " << std::endl;
		out << "       ||     " << std::endl;
		out << "       ||     " << std::endl;
		out << "	  /||+    " << std::endl;
		out.close();
	}
}