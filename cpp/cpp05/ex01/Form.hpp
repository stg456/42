/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:53:13 by stgerard          #+#    #+#             */
/*   Updated: 2023/07/07 11:06:52 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_nameDoc;
		bool				_signed;
		int const			_gradeToSigned;
		int const			_gradeToExecute;

	public:
		Form();
		Form(std::string nameDoc, int gradeToSigned, int gradeToExecute);
		Form(const Form &copy);
		Form & operator = (const Form & rhs);
		~Form();

		std::string	getName() const;
		void		beSigned(Bureaucrat &b);
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		class GradeTooHighException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator << (std::ostream & out, const Form & rhs);

#endif