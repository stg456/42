/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:10:35 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/20 13:16:29 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include <string>
// #include "ShrubberyCreationForm.hpp"  // forward declaration of ShrubberyCreationForm class
// #include "RobotomyRequestForm.hpp"    // surtout pas ça
// #include "PresidentialPardonForm.hpp"

class AForm;

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
		void		signForm(AForm &f);
		void		executeForm(AForm const & f);

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