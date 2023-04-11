/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:36:53 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/10 14:38:15 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	zombie("Bob");
	
	randomChump("Jo");
	zombie.announce();
	Zombie *a = newZombie("charles");
	a->announce();
	delete a;

	return (0);
}
