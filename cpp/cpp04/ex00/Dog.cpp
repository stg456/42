/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:27:47 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/12 10:38:51 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) {
	std::cout << "Dog constructor with type called" << std::endl;
}

Dog::Dog(const Dog &copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog& Dog::operator = (const Dog &rhs) {
	std::cout << "Dog assignement operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	return (*this);
}

Dog::~Dog() {std::cout << "Dog destructor called" << std::endl;}