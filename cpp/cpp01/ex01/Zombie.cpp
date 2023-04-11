/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:40:24 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/11 16:49:11 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "Zombie";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "constructor of " << this->name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "destructor of " << this->name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::zombieName(std::string name, int i)
{
	// join name et i
	this->name += ' ';
	this->name += (i + '1');
}
