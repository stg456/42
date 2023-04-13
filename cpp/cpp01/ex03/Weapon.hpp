/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:43:52 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/13 12:16:12 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# include WEAPON_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <array>

class Weapon
{
private:
	std::string	_type;

public:
	Weapon(std::string type);
	~Weapon();

std::string	getType();
void		setType(std::string type);

};

#endif