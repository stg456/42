/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:53:13 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/21 14:39:00 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_nameDoc;
		bool				_signed;
		int const			_gradeToSigned;
		int const			_gradeToExecute;

	public:
		AForm(void);
		AForm::AForm(std::string nameDoc, bool signed, int gradeToSigned, int gradeToExecute);
		AForm(const AForm &copy);
		virtual AForm & operator = (const AForm & rhs);
		virtual ~AForm(void);

		void		beSigned(Bureaucrat &b);
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		virtual std::string		getTarget(void) const = 0;
		virtual void			execute(Bureaucrat const & executor) const = 0;
		
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

std::ostream & operator << (std::ostream & out, const AForm & rhs);

#endif