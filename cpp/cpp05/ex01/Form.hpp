/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:53:13 by stgerard          #+#    #+#             */
/*   Updated: 2023/07/07 14:31:20 by stgerard         ###   ########.fr       */
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
		Form(void);
		Form(std::string nameDoc, int gradeToSigned, int gradeToExecute);
		Form(const Form &copy);
		Form & operator = (const Form & rhs);
		~Form(void);

		void		beSigned(Bureaucrat &b);
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		
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