/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:38:20 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/14 11:42:51 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Intern
{
	private:
		Form *		(*_form[3])(std::string target);
		std::string	_formName[3];
	
	public:
		Intern(void);
		Intern(const Intern &copy);
		Intern & operator = (const Intern & rhs);
		~Intern(void);

		Form *		makeForm(std::string formName, std::string target);
		Form *		makeShrubberyCreationForm(std::string target);
		Form *		makeRobotomyRequestForm(std::string target);
		Form *		makePresidentialPardonForm(std::string target);
};

#endif