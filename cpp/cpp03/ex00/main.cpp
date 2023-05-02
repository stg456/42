/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:54:24 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/02 17:05:53 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) 
{
	ClapTrap	round;

	round.attack("Joe");
	round.takeDamage(3);
	round.beRepaired(2);
	round.attack("Bob");
	round.takeDamage(3);
	round.beRepaired(2);

	return 0;
}