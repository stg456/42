/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:44:25 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/15 15:50:28 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat default constructor called" << std::endl;
}

// WrongCat::WrongCat(std::string type) {
// 	std::cout << "WrongCat constructor with type called" << std::endl;
// }

WrongCat::WrongCat(const WrongCat &copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator = (const WrongCat &rhs) {
	std::cout << "WrongCat assignement operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	return (*this);
}

WrongCat::~WrongCat() {std::cout << "WrongCat destructor called" << std::endl;}

void	WrongCat::makeSound() const {std::cout << "Wrong Meoh !" << std::endl;}
