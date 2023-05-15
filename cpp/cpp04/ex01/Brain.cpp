/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:44:12 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/15 11:02:10 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.cpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
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
	this->type = rhs.type;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
	return ;
}