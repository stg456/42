/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:44:15 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/23 15:57:33 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <iostream>

Base* Base::generate(void) {
	std::srand(std::time(0)); // la generation du code aleatoire sur la graine fonction du temps

	int i = std::rand();
	{
		// if (i % 3 == 0)
		// 	std::cout << executor.getName() << " has been robotomized." << std::endl;
		// else
		// 	std::cout << executor.getName() << " has not been robotomized." << std::endl;
	}
}

void identify_from_pointer(Base* p) {

}

void identify_from_reference(Base & p) {

}