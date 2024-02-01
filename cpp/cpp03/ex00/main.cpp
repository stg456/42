/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:54:24 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/11 13:59:01 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) 
{
	ClapTrap	round("Bob");

	round.attack("Joe");
	round.takeDamage(0);
	round.beRepaired(0);
	round.attack("Bob");
	round.takeDamage(0);
	round.beRepaired(0);

	return 0;
}