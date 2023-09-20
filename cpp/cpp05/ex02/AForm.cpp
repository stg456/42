/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:53:32 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/20 12:57:53 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _nameDoc(""), _signed(0), _gradeToSigned(150), _gradeToExecute(150) {}

AForm::AForm(std::string nameDoc, int gradeToSigned, int gradeToExecute) : _nameDoc(nameDoc), _gradeToSigned(gradeToSigned), _gradeToExecute(gradeToExecute) {
	(void) nameDoc;
	if (gradeToSigned < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSigned > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm & copy) : _nameDoc(copy._nameDoc), _gradeToSigned(copy._gradeToSigned), _gradeToExecute(copy._gradeToExecute) {
	*this = copy;
}

AForm & AForm::operator = (const AForm & rhs) {
	if (this == &rhs)
		return *this;
	this->_signed = rhs._signed;
	return *this;
}

std::string	AForm::getName(void) const {
	return (this->_nameDoc);
}

void		AForm::beSigned(Bureaucrat &b) {
	if (b.getGrade() > this->_gradeToSigned)
		throw AForm::GradeTooLowException();
	this->_signed = 1;
}

bool		AForm::getSigned(void) const {
	return (this->_signed);
}

int			AForm::getGradeToSign(void) const {
	return (this->_gradeToSigned);
}

int			AForm::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

AForm::~AForm(void) {}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Exception: Grade Too High");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Exception: Grade Too Low");
}

std::ostream & operator << (std::ostream & out, const AForm & rhs) {
	out << rhs.getName() << " gradeSign " << rhs.getGradeToSign() << ", is ";
	if (rhs.getSigned())
		out <<  "signed" << std::endl;
	else
		out << "not signed" << std::endl;
	return (out);
}

// std::string	getTarget(void) {}

// void	execute(Bureaucrat const & executor) {
// 	if (executor.getGrade() > _gradeToExecute())
// 		throw Form::GradeTooLowException();
// }
