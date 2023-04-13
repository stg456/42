/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:45:04 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/13 17:05:20 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack() 
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

