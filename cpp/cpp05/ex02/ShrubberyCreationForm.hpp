/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:44:02 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/20 11:41:01 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>
#include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string str);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm & operator = (const ShrubberyCreationForm & rhs);
		~ShrubberyCreationForm();

		class GradeTooLowException : public std::exception 
		{
			public:
				virtual const char *what() const throw();
		};

		std::string	getTarget() const;
		void		execute(Bureaucrat const & executor) const;
};

#endif
