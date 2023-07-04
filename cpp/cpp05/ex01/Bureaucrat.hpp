/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:10:35 by stgerard          #+#    #+#             */
/*   Updated: 2023/07/04 17:29:49 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int i);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat & operator = (const Bureaucrat & rhs);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		upGrade();
		void		downGrade();
		void		signForm(Form &f);

		class GradeTooHighException : public std::exception 
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream & operator << (std::ostream & out, const Bureaucrat & rhs);

#endif