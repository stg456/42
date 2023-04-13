/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:44:16 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/13 12:37:59 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# include HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"


class HumanA
{
public:
	HumanA(std string name, std::string weapon);
	~HumanA();

void	attack();

private:
	std::string	_name;
	Weapon		_weapon;
};

#endif