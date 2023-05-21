/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:31:15 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/20 20:06:46 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->_type = "Cat";
	std::cout << "Cat default constructor called with the new Brain" << std::endl;
	this->_Brain = new Brain();
	return ;
}

// Cat::Cat(std::string type) {
// 	std::cout << "Cat constructor with type called" << std::endl;
// }

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

Cat::~Cat() {
	std::cout << "Cat destructor called with the delete Brain" << std::endl;
	delete _Brain;
}

void	Cat::makeSound() const {
	std::cout << "Meoh" << std::endl;
}

std::string		Cat::getType() const {
	return (this->_type);
}
