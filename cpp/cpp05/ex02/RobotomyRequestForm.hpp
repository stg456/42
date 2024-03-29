/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:47:21 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/20 11:41:01 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib> // Inclure la bibliothèque pour les fonctions de génération aléatoire
#include <ctime>	// Inclure la bibliothèque pour l'initialisation de la graine

class Bureaucrat;
// class Form; // pb: forward declaration of Form class

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm & operator = (const RobotomyRequestForm & rhs);
		~RobotomyRequestForm();

		class GradeTooLowException : public std::exception 
		{
			public:
				virtual const char *what() const throw();
		};

		std::string	getTarget() const;
		void	execute(Bureaucrat const & executor) const;
};

#endif