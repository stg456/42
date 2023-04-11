/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:53:46 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/11 13:32:03 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombie;

	zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombie[i].zombieName(name);
		zombie[i].announce();
	}

	return (zombie);
}