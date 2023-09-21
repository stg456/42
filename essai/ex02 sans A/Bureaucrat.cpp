/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:09:54 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/20 14:51:57 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bill"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
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
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void  Bureaucrat::downGrade() {
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat & rhs) {
	if (this == &rhs)
		return *this;
	// this->_grade = rhs._grade;
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Exception: Grade Too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Exception: Grade Too Low");
}

std::ostream & operator << (std::ostream & out, const Bureaucrat & rhs) {
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (out);
}

void	Bureaucrat::signForm(Form &f) {
	if (f.getSigned() == 1 )
		std::cout << this->_name << " always signed " << f.getName() << std::endl;
	else if (f.getSigned() == false && f.getGradeToSign() < this->getGrade())
		std::cout << this->_name << " couldn't sign " << f.getName() << " because his grade is too low to sign" << std::endl;
	else if (f.getSigned() == false && f.getGradeToSign() >= this->getGrade())
		std::cout << this->_name << " sign " << f.getName() << " because his grade permit him to sign" << std::endl;
	f.beSigned(*this);
}

void	Bureaucrat::executeForm(Form const & f) {
	// if ((!f.getGradeToExecute()) || !f.getSigned())
	// 	std::cout << f.getName() << " couldn't execute " << f.getTarget() << " because his grade is too low to execute" << std::endl;
	// else if (f.getGradeToExecute() >= getGrade()) {
	// 	std::cout << f.getName() << " executed " << f.getTarget() << std::endl;
	if (f.getSigned() == true) {
		f.execute(*this);
		std::cout << this->_name << " executed " << f.getName() << std::endl;
	}
	else
		std::cout << this->_name << " couldn't execute " << f.getName() << " because this form is not signed." << std::endl;
}