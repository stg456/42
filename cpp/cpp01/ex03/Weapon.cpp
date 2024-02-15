/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:45:43 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/19 17:43:00 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	this->_type = type;
	return ;
}

Weapon::~Weapon() {}

// std::string Weapon::getType() const
const std::string& Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}
