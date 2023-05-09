/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:54:24 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/09 18:39:38 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void) 
{
	ClapTrap	round("Bob");

	round.attack("Joe");
	round.takeDamage(3);
	round.beRepaired(2);
	round.attack("Bob");
	round.takeDamage(3);
	round.beRepaired(2);

	return 0;
}