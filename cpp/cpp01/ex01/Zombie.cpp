/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:40:24 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/21 12:36:25 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	// this->_name = "";
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "constructor of " << this->_name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "destructor of " << this->_name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::zombieName(std::string name, int i)
{
	// join name et i
	this->_name = name;
	this->_name += (i + '1');
}
