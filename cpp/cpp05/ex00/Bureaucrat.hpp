/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:10:35 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/26 15:34:36 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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
		// virtual exception () {};
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		upGrade();
		void		downGrade();

		class GradeTooHighException : public exception {
			const char *what() const throw();
		};
		class GradeTooLowException : public exception {
			const char *what() const throw();
		};
};

#endif