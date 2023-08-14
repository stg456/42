/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:53:32 by stgerard          #+#    #+#             */
/*   Updated: 2023/08/14 14:38:09 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _nameDoc(""), _signed(0), _gradeToSigned(0), _gradeToExecute(0) {}

Form::Form(std::string nameDoc, int gradeToSigned, int gradeToExecute) : _nameDoc(nameDoc), _signed(0), _gradeToSigned(gradeToSigned), _gradeToExecute(gradeToExecute) {
	(void) nameDoc;
	if (gradeToSigned < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSigned > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form & copy) : _nameDoc(copy._nameDoc), _gradeToSigned(copy._gradeToSigned), _gradeToExecute(copy._gradeToExecute) {
	*this = copy;
}

Form & Form::operator = (const Form & rhs) {
	if (this == &rhs)
		return *this;
	this->_signed = rhs._signed;
	return *this;
}

std::string	Form::getName(void) const {
	return (this->_nameDoc);
}

void		Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() > this->_gradeToSigned)
		throw Form::GradeTooLowException();
	this->_signed = 1;
}

bool		Form::getSigned(void) const {
	return (this->_signed);
}

int			Form::getGradeToSign(void) const {
	return (this->_gradeToSigned);
}

int			Form::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

Form::~Form(void) {}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Exception: Grade Too High");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Exception: Grade Too Low");
}

std::ostream & operator << (std::ostream & out, const Form & rhs) {
	out << rhs.getName() << " gradeSign " << rhs.getGradeToSign() << ", is signed "<< rhs.getSigned() << std::endl;
	return (out);
}
