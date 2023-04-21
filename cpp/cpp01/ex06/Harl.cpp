/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:16:46 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/20 15:08:55 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug( void )
{
	std::cout << "Oulala c'est le niveau où ça commence à merder !" << std::endl;
}

void Harl::info( void )
{
	std::cout << "Attention ça va te peter à la gueule !" << std::endl;
}

void Harl::warning( void )
{
	std::cout << " 5...4...3...2... t'es sur que tu veux rester là !" << std::endl;
}

void Harl::error( void )
{
	std::cout << "oyé t'es planté !" << std::endl;
}

void Harl::complain(std::string level)
{
	int i;
	void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; // les 2eme () sont necessaire

	std::string msg[4] = {"debug","info","warning","error"};

	for (i = 0; i < 4; i++)
	{
		if (level == msg[i])
			(this->*(ptr[i]))();
	}
	// if (i < 0 || i > 4)
	// 	std::cout << "Message inconnu: 42 style, demmerde toi !" << std::endl;
}
