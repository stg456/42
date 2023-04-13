/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:44:37 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/13 12:37:59 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# include HUMANB_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <array>

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB();

void	attack();

private:
	std::string nameB;
	std::string weaponB;



};

#endif