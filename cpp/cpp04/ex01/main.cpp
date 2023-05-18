/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:09:29 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/18 16:37:56 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#define N 10

int main() 
{
    const Animal* meta[N];
	for (int i = 0; i < N; i++)
	{
		if (i % 2)
		{
			meta[i] = new Dog();
			meta[i]->makeSound();
			meta[i]->Brain::setIdea("balle", i);
			meta[i]->Brain::getIdeas(i);
			std::cout << this->meta[i] << std::endl;
		}
		else
		{
			meta[i] = new Cat();
			meta[i]->makeSound();
		}
	}

	for (int i = 0; i < N; i++)
	{
		delete meta[i];
	}

	return 0;
}