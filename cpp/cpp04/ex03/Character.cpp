/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:25:18 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/22 11:30:03 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// ICharacter::ICharacter() {}

// ICharacter::ICharacter(std::string const &name) {}

// ICharacter::ICharacter(const ICharacter &copy) {}

// ICharacter & ICharacter::operator = (const ICharacter &rhs) {}

ICharacter::~ICharacter() {}

std::string const & ICharacter::getName() const {}

void	ICharacter::equip(AMateria* m) {}

void	ICharacter::unequip(int idx) {}

void	ICharacter::use(int idx, ICharacter &target) {}

