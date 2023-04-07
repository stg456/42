/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:39:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/07 16:56:23 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <array>

class Zombie
{
private:
	std::string	name;

public:
	Zombie(/* args */);
	void	announce(void);

	~Zombie();
};



Zombie::Zombie(/* args */)
{
}

Zombie::~Zombie()
{
}


#endif