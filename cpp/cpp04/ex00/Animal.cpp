/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:08:03 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/12 10:38:51 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) {
	std::cout << "Animal constructor with type called" << std::endl;
}

Animal::Animal(const Animal &copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal& Animal::operator = (const Animal &rhs) {
	std::cout << "Animal assignement operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	return *this;
}

Animal::~Animal() {std::cout << "Animal destructor called" << std::endl;}

std::string	Animal::getType() {

}

void	Animal::makeSound() {std::cout << "" << std::endl;}
