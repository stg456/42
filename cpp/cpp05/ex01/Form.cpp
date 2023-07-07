/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:53:32 by stgerard          #+#    #+#             */
/*   Updated: 2023/07/07 10:46:48 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(): _nameDoc("Formulaire"), _signed(false), _gradeToSigned(), _gradeToExecute() {}

Form::Form(std::string nameDoc, int gradeToSigned, int gradeToExecute) : _nameDoc(), _signed(false), _gradeToSigned(), _gradeToExecute() {
	if (gradeToSigned < 1 || gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	if (gradeToSigned > 150 || gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form & copy) : _nameDoc(), _signed(false), _gradeToSigned(), _gradeToExecute() {
	*this = copy;
}

Form & Form::operator = (const Form & rhs) {
	if (this == &rhs)
		return *this;
	this->_signed = rhs._signed;
	return *this;
}

std::string	getName() const {
	return (this->_nameDoc);
}

void		beSigned(Bureaucrat &b) {}

bool		getSigned() const {return (this->_signed);}

int			getGradeToSign() const {}

int			getGradeToExecute() const {}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Exception: Grade Too High");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Exception: Grade Too Low");
}

std::ostream & operator << (std::ostream & out, const Form & rhs) {
	out << "je sais pas encore" << std::endl;
}