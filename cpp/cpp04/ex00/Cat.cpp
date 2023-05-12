/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:31:15 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/12 11:58:51 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) {
	std::cout << "Cat constructor with type called" << std::endl;
}

Cat::Cat(const Cat &copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat& Cat::operator = (const Cat &rhs) {
	std::cout << "Cat assignement operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	return (*this);
}

Cat::~Cat() {std::cout << "Cat destructor called" << std::endl;}

void	Cat::makeSound() {
	std::cout << "Meoh" << std::endl;
}