/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:44:12 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/20 19:35:12 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <stdlib.h>

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	// for (int i = 1; i <= 100; i++)
	// {
	// 	this->_ideas[i] = "ideas ";
	// 	this->_ideas[i] += i + '0';
	// }
	std::string ideas[] = {"sleep", "play", "eat", "do something stupid"};
	for (int i = 0; i < 100; i++)
		*this->_ideas = ideas[i % 4]; // pq * ?!
	return ;
}

// void	Brain::setIdea(std::string idea, int i)
// {
// 	if (i >= 0 && i < 100)
// 		this->_ideas[i] = idea;
// }

// Animal::Animal(std::string type) {
// 	std::cout << "Animal constructor with type called" << std::endl;
// }

Brain::Brain(const Brain &copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain& Brain::operator = (const Brain &rhs) {
	std::cout << "Brain assignement operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	// std::cout << this->_ideas << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

std::string	Brain::getIdeas(int i) {
	// std::cout << this->_ideas << std::endl;
	return (this->_ideas[i]);
}
