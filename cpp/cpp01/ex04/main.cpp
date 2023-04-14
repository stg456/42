/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:41:28 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/14 14:39:42 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	std::string	fichier;
	std::string	s1 = "toto";
	std::string	s2 = "titi";

	std::ofstream f("fichier.txt");
	if (!f.is_open())
		std::cout << "Impossible d'ouvrir le fichier en écriture !" << std::endl;
	else
	{
		;
	}
	f.close();
	return 0;	
}
