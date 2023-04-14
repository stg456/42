/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:43:52 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/14 11:41:00 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
public:
	Weapon(std::string type);
	~Weapon();
	std::string	getType() const;
	void		setType(std::string type);

private:
	std::string	_type;

};

#endif