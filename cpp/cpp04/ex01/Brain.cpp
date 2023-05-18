/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:44:12 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/18 15:07:00 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 1; i <= 100; i++)
		this->_ideas[i] = "ideas " + i;
	return ;
}

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
	// this->_type = rhs._type;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

std::string	getIdeas(int i) const {
	return (this->_ideas[i]);
}
