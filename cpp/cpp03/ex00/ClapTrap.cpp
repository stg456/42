/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:53:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/09 11:37:11 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Constructor with Name called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy; // le this permet de pas se les cogner 1 par 1
	// _name = copy._name;
	// _attackDamage = copy._attackDamage;
	// _energyPoints = copy._energyPoints;
	// _hitPoints = copy._hitPoints;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &rhs) {
	std::cout << "Assignement operator called" << std::endl;
	if (this == &rhs) // & pour rhs et * pour this
		return (*this);
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap() {std::cout << "Destructor called" << std::endl;}


void ClapTrap::attack(const std::string &target) {
	if (this->_energyPoints >= 0 && this->_hitPoints >= 0) 
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << _attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "energy points is empty or Death !" << std::endl;
	this->_name = target;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0)
	{
		std::cout << "You are dead, you can't take damage" << std::endl;
		return ;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage" << std::endl;
		this->_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0)
	{
		std::cout << "You are dead, it's too late to be repaired !" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "Without energy, you can't be repaired !" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " be repaired " << amount << " points of damage" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
}
