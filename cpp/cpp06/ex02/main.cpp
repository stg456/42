/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:49:57 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/04 11:36:12 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <iostream>
#include <cstdlib> // Inclure la bibliothèque pour les fonctions de génération aléatoire
#include <ctime>	// Inclure la bibliothèque pour l'initialisation de la graine

int main()
{
	std::srand(std::time(0));

	Base* base = generate();

	identify(base);

	identify(*base);

	delete base;

	std::cout << std::endl;

	return 0;
}
