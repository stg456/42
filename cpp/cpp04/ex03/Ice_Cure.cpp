/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice_Cure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:02:39 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/22 11:30:03 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

Ice& Ice::operator = (const Ice &rhs) {

	std::cout << "* shoots an ice bolt at ";
	std::cout << rhs.name << std::endl;
}

Cure Cure::operator = (const Cure &rhs) {}