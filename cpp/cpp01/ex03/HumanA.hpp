/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:44:16 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/14 11:45:04 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"


class HumanA
{
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void	attack();

private:
	std::string	_name;
	Weapon		&_weapon;
};

#endif