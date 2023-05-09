/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:54:24 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/09 18:10:25 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) 
{
	ClapTrap	clapTrap("Bob");
	ScavTrap	scavTrap("Jack");

	clapTrap.attack("Joe");
	clapTrap.takeDamage(3);
	clapTrap.beRepaired(2);
	clapTrap.attack("Jack");
	clapTrap.takeDamage(3);
	clapTrap.beRepaired(2);

	scavTrap.attack("Jack");
	scavTrap.takeDamage(3);
	scavTrap.beRepaired(2);
	scavTrap.guardGate();


	return 0;
}