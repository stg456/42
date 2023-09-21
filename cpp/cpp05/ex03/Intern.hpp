/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:38:20 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/21 09:53:09 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
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

		AForm *		makeForm(std::string formName, std::string target);
		AForm *		Shrub(std::string target);
		AForm *		Robot(std::string target);
		AForm *		Presid(std::string target);
};

#endif