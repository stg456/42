/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:05:43 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/20 14:50:50 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
	private:
		std::string	_target;
	
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm & operator = (const PresidentialPardonForm & rhs);
		~PresidentialPardonForm();

		class GradeTooLowException : public std::exception 
		{
			public:
				virtual const char *what() const throw();
		};

		std::string	getTarget() const;
		void	execute(Bureaucrat const & executor) const;
};

#endif