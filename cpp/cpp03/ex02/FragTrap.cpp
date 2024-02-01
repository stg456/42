/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:34:11 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/10 14:49:15 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "FragTrap constructor with name called" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &copy) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = copy; // le this permet de pas se les cogner 1 par 1
	// _name = copy._name;
	// _attackDamage = copy._attackDamage;
	// _energyPoints = copy._energyPoints;
	// _hitPoints = copy._hitPoints;
}

FragTrap& FragTrap::operator = (const FragTrap &rhs) {
	std::cout << "FragTrap assignement operator called" << std::endl;
	if (this == &rhs) // & pour rhs et * pour this
		return (*this);
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::attack(const std::string &target) {
	if (this->_energyPoints >= 0 && this->_hitPoints >= 0) 
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << " causing " << _attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "energy points is empty or Death !" << std::endl;
	this->_name = target;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap make a high five" << std::endl;
}
