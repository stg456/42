/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:45:43 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/13 12:37:59 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	type = _type;
	return ;
}

Weapon::~Weapon() {}

std::string Weapon	getType()
{
	return (_type);
}

void	setType(std::string type)
{
	_type = type;
}