/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:54:24 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/11 14:09:24 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void) 
{
	ClapTrap	clapTrap("Bob");
	FragTrap	FragTrap("Jack");

	clapTrap.attack("John");
	clapTrap.takeDamage(30);
	clapTrap.beRepaired(2);
	clapTrap.attack("Bob");
	clapTrap.takeDamage(30);
	clapTrap.beRepaired(2);

	FragTrap.attack("Bob");
	FragTrap.takeDamage(30);
	FragTrap.beRepaired(2);
	FragTrap.highFivesGuys();

	return 0;
}