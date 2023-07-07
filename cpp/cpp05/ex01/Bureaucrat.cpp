/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:09:54 by stgerard          #+#    #+#             */
/*   Updated: 2023/07/07 16:25:10 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int i) : _name(name) {
	if (i < 1)
		throw Bureaucrat::GradeTooHighException();
	if (i > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = i;
}

Bureaucrat::Bureaucrat(const Bureaucrat & copy) {
	*this = copy;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void  Bureaucrat::upGrade() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void  Bureaucrat::downGrade() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat & rhs) {
	if (this == &rhs)
		return *this;
	this->_grade = rhs._grade;
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Exception: GradeTooHigh");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Exception: GradeTooLow");
}

std::ostream & operator << (std::ostream & out, const Bureaucrat & rhs) {
	out << rhs.getName() << " , bureaucrat grade " << rhs.getGrade() << std::endl;
	return (out);
}

void	Bureaucrat::signForm(Form &f) {
	if (f.getSigned() == true)
		std::cout << Bureaucrat::getName() << "signed" << f.getName() << std::endl;
	else 
		std::cout << Bureaucrat::getName() << "couldn't sign" << f.getName() << std::endl;
	return ;
}