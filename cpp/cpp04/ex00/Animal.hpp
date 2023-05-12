/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:40:04 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/12 10:38:51 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &copy);
		Animal& operator = (const Animal &rhs);
		~Animal();

		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif