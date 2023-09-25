/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:42:13 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/25 16:03:08 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include <iostream>
#include <cstdlib> // Inclure la bibliothèque pour les fonctions de génération aléatoire
#include <ctime>	// Inclure la bibliothèque pour l'initialisation de la graine

class Base 
{
	public:
		virtual ~Base();

	Base*	generate(void);
};

class A : public Base {};

class B : public Base {};

class C : public Base {};


Base* generate(void);

void identify_from_pointer(Base* p);

void identify_from_reference(Base & p);

#endif
