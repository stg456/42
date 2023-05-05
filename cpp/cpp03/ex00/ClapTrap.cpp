/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:53:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/05 16:28:06 by stgerard         ###   ########.fr       */
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
	_name = copy._name;
	_attackDamage = copy._attackDamage;
	_energyPoints = copy._energyPoints;
	_hitPoints = copy._hitPoints;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &rhs) {
	if (this == rhs)
		return (*this);
	this->_name = rhs._name;

	return *this;
}

ClapTrap::~ClapTrap() {std::cout << "Destructor called" << std::endl;}

void ClapTrap::attack(const std::string &target) {
	if (_energyPoints && _hitPoints) 
	{
		std::cout << "ClapTrap " << _name << "attacks " << target << "causing" << _attackDamage << "points of damage" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "energy points is empty" << std::endl;
	_name = target;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << "take " << amount << "points of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << _name << "be repaired " << amount << "points of damage" << std::endl;
}
