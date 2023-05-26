/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:10:35 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/26 16:20:51 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;

		std::string	getName();
		std::string	getGrade();

	public:
		Bureaucrat(std::string name);
		
		~Bureaucrat();
};

		Bureaucrat::GradeTooHighException();
		Bureaucrat::GradeTooLowException();
