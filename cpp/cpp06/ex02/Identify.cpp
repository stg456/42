/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:44:15 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/04 12:00:36 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <iostream>

Base::~Base() {}

Base* generate(void) {

	std::srand(std::time(0));
	int i = std::rand();
	{
		if (i % 2 == 0)
			return new A;
		else if (i % 3 == 0)
			return new B;
		else
			return new C;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base & p) {
	try
	{
		A	&a_class = dynamic_cast<A&>(p);
		std::cout << "Identify with reference: Class Type A" << std::endl;
		(void) a_class;
	}
	catch(std::exception &e) {}

	try
	{
		B	&b_class = dynamic_cast<B&>(p);
		std::cout << "Identify with reference: Class Type B" << std::endl;
		(void) b_class; 
	}
	catch(std::exception &e) {}

	try
	{
		C	&c_class = dynamic_cast<C&>(p);
		std::cout << "Identify with reference: Class Type C" << std::endl;
		(void) c_class;
	}
	catch(std::exception &e) {}
}
