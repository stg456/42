/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:36:53 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/11 13:59:04 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	*zombie;
	int nb = 6;
	// std::string name = nb + 1;
	
	zombie = zombiehorde(nb, "Bob");
	zombie.announce();

	delete *zombie;

	return (0);
}
