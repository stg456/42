/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:41:28 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/15 17:46:52 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	std::string		str = (av[1]);
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::ifstream	myfile = str + ".replace";

	std::cout << myfile.replace << std::endl;

	if (ac != 4)
	{
		std::cout << "Erreur dans le nombre d'arguments !" << std::endl;
		return 0;
	}

	if (!myfile)
	{
		std::cout << "Erreur, il n'y a pas de fichier !" << std::endl;
		return 0;
	}

	if (s1.empty() || s2.empty())
	{
		std::cout << "Erreur dans les arguments à remplacer !" << std::endl;
		return 0;
	}






	
	// if (myfile.open())
	// {
	// 	while (getline(myfile, buf))
	// 	{
	// 		if ()
	// 		{

	// 		}
	// 	}
	// }
	// else
	// 	std::cout << "Impossible de lire le fichier !" << std::endl;




	// myfile.close();
	
	return 0;	
}
