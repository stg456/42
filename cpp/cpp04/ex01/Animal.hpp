/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:40:04 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/15 11:47:07 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string _type;
	
	public:
		Animal();
		// Animal(std::string type);
		Animal(const Animal &copy);
		Animal& operator = (const Animal &rhs);
		virtual ~Animal();

		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif