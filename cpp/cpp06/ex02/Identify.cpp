/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:44:15 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/25 10:14:15 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <iostream>

Base* Base::generate(void) {
	std::srand(std::time(0)); // la generation du code aleatoire sur la graine fonction du temps

	int i = std::rand(std::time(0));
	{
		if (i % 2 == 0)
			return new A;
		else if (i % 3 == 0)
			return new B;
		else
			return new C;
	}
}

void identify_from_pointer(Base* p) {

}

void identify_from_reference(Base & p) {

}