/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:39:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/21 12:36:25 by stgerard         ###   ########.fr       */
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
	std::string	_name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	announce(void);
	void	zombieName(std::string name, int i);
};

Zombie* zombieHorde(int N, std::string name);

#endif