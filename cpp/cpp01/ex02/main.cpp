/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:36:53 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/12 16:46:35 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Zombie.hpp"
#include <iostream>

int main()
{
	// Zombie		*zombie;
	std::string	str = "HI THIS IS BRAIN";
	std::string stringPTR;
	std::string stringREF;
	
// 	Votre programme doit afficher :
// • L’adresse de la string en mémoire.
// • L’adresse stockée dans stringPTR.
// • L’adresse stockée dans stringREF.
// Puis :
// • La valeur de la string.
// • La valeur pointée par stringPTR.
// • La valeur pointée par stringREF.

	std::cout << "adresse de la string en mémoire: " << &str << std::endl;
	stringPTR == &str;
	std::cout << "adresse stockée dans stringPTR: " << stringPTR << std::endl;
	stringREF = *str;
	std::cout << "adresse stockée dans stringREF: " << stringREF << std::endl;


	return (0);
}
