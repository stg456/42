/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:36:53 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/11 16:33:34 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	*zombie;
	
	zombie = zombieHorde(6, "Bob");
	// zombie.announce();

	delete []zombie;

	return (0);
}
