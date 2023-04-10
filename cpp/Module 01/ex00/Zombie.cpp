/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:40:24 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/10 13:08:57 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::zombie(std string::name)
{
	this->name = name;
}

Zombie::~zombie() {}

void	zombie::announce(void)
{
	st::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	randomChump(std::string name)
{

}