/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:53:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/02 18:10:07 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
	_name = "Bob";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "Constructor with Name called" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap ClapTrap::operator=(const ClapTrap& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
// 	this->_fix = rhs.getRawBits();
// 	return *this;
}

ClapTrap::~ClapTrap() {std::cout << "Destructor called" << std::endl;}

void attack(const std::string& target) {
	std::cout << "ClapTrap " << _name << "attacks " << target << "causing" << damage << "points of damage" << std::endl;
}

void takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << "take " << amount << "points of damage" << std::endl;
}

void beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << _name << "be repaired " << amount << "points of damage" << std::endl;
}