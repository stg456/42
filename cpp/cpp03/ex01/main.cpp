/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:54:24 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/11 14:04:54 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) 
{
	ClapTrap	clapTrap("Bob");
	ScavTrap	scavTrap("Jack");

	clapTrap.attack("Joe");
	clapTrap.takeDamage(20);
	clapTrap.beRepaired(2);
	clapTrap.attack("Bob");
	clapTrap.takeDamage(20);
	clapTrap.beRepaired(2);

	scavTrap.attack("Joe");
	scavTrap.takeDamage(20);
	scavTrap.beRepaired(2);
	scavTrap.guardGate();


	return 0;
}