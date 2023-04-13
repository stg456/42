/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:45:25 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/13 16:29:55 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB() {}

void	setWeapon(Weapon weapon)
{
	this->_weapon = &weapon;
}

void	attack() 
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}