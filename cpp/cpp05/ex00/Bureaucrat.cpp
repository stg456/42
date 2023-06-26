/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:09:54 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/26 16:30:32 by stgerard         ###   ########.fr       */
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

Bureaucrat::Bureaucrat(const Bureaucrat & copy) {}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {return (this->_name);}

int Bureaucrat::getGrade() const {return (this->_grade);}

void  Bureaucrat::upGrade() {}

void  Bureaucrat::downGrade() {}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat & rhs) {
	if (this == &rhs)
		return *this;
	return *this;
}

