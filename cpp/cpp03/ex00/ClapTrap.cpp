/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:53:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/02 14:46:54 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string Name) {std::cout << "constructeur de ClapTrap" << std::endl;}

ClapTrap::~ClapTrap() {std::cout << "destructeur de ClapTrap" << std::endl;}

void attack(const std::string& target) {std::cout << "ClapTrap " << Name << "attacks " << target << "causing" << damage << "points of damage" << std::endl;}

void takeDamage(unsigned int amount) {std::cout << "ClapTrap " << Name << "take " << amount << "points of damage" << std::endl;}

void beRepaired(unsigned int amount) {std::cout << "ClapTrap " << Name << "be repaired " << amount << "points of damage" << std::endl;}