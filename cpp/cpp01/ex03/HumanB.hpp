/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:44:37 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/13 15:37:52 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon weapon);
	void	attack();

private:
	std::string _name;
	std::string *_weapon;

};

#endif