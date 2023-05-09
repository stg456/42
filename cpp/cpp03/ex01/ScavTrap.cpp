/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:43:14 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/09 17:11:52 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap constructor with name called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	// *this->copy;
	// return *this;
}

ScavTrap& ScavTrap::operator = (const ScavTrap &rhs) {
	std::cout << "ScavTrap assignement operator called" << std::endl;
	if (this == &rhs) // & pour rhs et * pour this
		return (*this);
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (this->_energyPoints >= 0 && this->_hitPoints >= 0) 
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << _attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "energy points is empty or Death !" << std::endl;
	this->_name = target;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is enter in gate keeper mode " << std::endl;
	return ;
}
