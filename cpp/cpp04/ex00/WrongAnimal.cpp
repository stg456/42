/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:43:18 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/12 16:56:48 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

// WrongAnimal::WrongAnimal(std::string type) {
// 	std::cout << "WrongAnimal constructor with type called" << std::endl;
// }

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal &rhs) {
	std::cout << "WrongAnimal assignement operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	return *this;
}

WrongAnimal::~WrongAnimal() {std::cout << "WrongAnimal destructor called" << std::endl;}

void	WrongAnimal::makeSound() const {std::cout << "a WrongAnimal sound !" << std::endl;}