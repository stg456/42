/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:53:32 by stgerard          #+#    #+#             */
/*   Updated: 2023/07/04 18:03:30 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(): _nameDoc(), _signed(false), _gradeToSigned(), _gradeToExecute() {}

Form::Form(std::string nameDoc, int gradeToSigned, int gradeToExecute) : _nameDoc(), _signed(false), _gradeToSigned(), _gradeToExecute() {

}

Form::Form(const Form & copy) {
	*this = copy;
}

Form & Form::operator = (const Form & rhs) {
	if (this == &rhs)
		return *this;
	this->_grade = rhs._grade;
	return *this;
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Exception: GradeTooHigh");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Exception: GradeTooLow");
}

std::ostream & operator << (std::ostream & out, const Form & rhs) {}