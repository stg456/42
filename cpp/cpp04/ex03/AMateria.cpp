/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:36:05 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/21 16:46:25 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string type) {}

AMateria::AMateria(const AMateria &copy) {}

AMateria::~AMateria() {}

AMateria& AMateria::operator = (const AMateria &rhs) {} 

std::string const	& AMateria::getType() const; {}

AMateria* AMateria::clone() const {}

void	AMateria::use(ICharacter & target) {}