/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:10:35 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/20 14:53:45 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"
#include <string>
// #include "ShrubberyCreationForm.hpp"  // forward declaration of ShrubberyCreationForm class
// #include "RobotomyRequestForm.hpp"    // surtout pas ça
// #include "PresidentialPardonForm.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat & operator = (const Bureaucrat & rhs);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		upGrade();
		void		downGrade();
		void		signForm(Form &f);
		void		executeForm(Form const & f);

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