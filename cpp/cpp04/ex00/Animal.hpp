/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:40:04 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/11 15:03:30 by stgerard         ###   ########.fr       */
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

	void	makeSound();
};

class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &copy);
		Dog& operator = (const Dog &rhs);
		~Dog();
};

class Cat : public Animal
{
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &copy);
		Cat& operator = (const Cat &rhs);
		~Cat();
};

#endif