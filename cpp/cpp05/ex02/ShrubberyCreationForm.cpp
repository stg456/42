/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:01:47 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/13 14:26:21 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137), _target() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string str): Form(ShrubberyCreationForm, 0, 145, 137), _target(target) {
	if (this->getGradeToSign() < 145 || this->getGradeToExecute() < 137)
		throw ShrubberyCreationForm::GradeTooLowException();
	return ;
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
	if (this->getSigned() == false || (executor.getGrade() > this->getGradeToExecute()))
		throw ShrubberyCreationForm::GradeTooLowException();
	else {
		std::cout << executor.getName() << " has create Shrubbery." << std::endl;
		std::ofstream out;
		if (!out)
		{
			std::cerr << "Error: cannot create file." << std::endl;
			return ;
		}
		out.open(this->_target + "_Shrubbery", std::ios::out);
		out << "  o__o___o__o " << std::endl;
		out << "    o/_/_/o   " << std::endl;
		out << "       ||     " << std::endl;
		out << "       ||     "<< std::endl;
		out << "	  /||+    " << std::endl;
		out.close();
	}
}