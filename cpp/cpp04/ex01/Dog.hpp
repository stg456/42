/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:24:25 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/21 15:35:23 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		// Dog(std::string type);
		Dog(const Dog &copy);
		Dog& operator = (const Dog &rhs);
		virtual ~Dog();
		
		virtual std::string		getType() const;
		virtual void	makeSound() const;

	private:
		Brain	*_Brain;
};

#endif