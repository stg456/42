/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:54:24 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/10 15:17:13 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void) 
{
	ClapTrap	clapTrap("Bob");
	FragTrap	FragTrap("John");

	clapTrap.attack("John");
	clapTrap.takeDamage(3);
	clapTrap.beRepaired(2);
	clapTrap.attack("John");
	clapTrap.takeDamage(3);
	clapTrap.beRepaired(2);

	FragTrap.attack("Bob");
	FragTrap.takeDamage(3);
	FragTrap.beRepaired(2);
	FragTrap.highFivesGuys();

	return 0;
}