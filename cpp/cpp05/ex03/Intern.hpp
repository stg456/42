/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:38:20 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/15 11:38:03 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{	
	public:
		Intern(void);
		Intern(const Intern &copy);
		Intern & operator = (const Intern & rhs);
		~Intern(void);

		Form *		makeForm(std::string formName, std::string target);
		Form *		Shrub(std::string target);
		Form *		Robot(std::string target);
		Form *		Presid(std::string target);
};

#endif