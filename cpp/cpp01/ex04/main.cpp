/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:41:28 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/14 16:01:35 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	std::string	str;
	std::string	buf;
	int 		i;
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	std::ifstream myfile (av[1]);

	if (myfile.open())
	{
		
	}
	else
		std::cout << "Impossible de lire le fichier !" << std::endl;



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
