/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:41:28 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/15 18:09:46 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	std::string		str;
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::ifstream	myfile (av[1]);

	if (ac != 4)
	{
		std::cout << "Bad number of arguments !" << std::endl;
		return 0;
	}

	if (!myfile)
	{
		std::cout << "Unable to read the file !" << std::endl;
		return 0;
	}

	if (s1.empty() || s2.empty())
	{
		std::cout << "Error in the arguments to replace !" << std::endl;
		return 0;
	}

	// std::cout << myfile.replace << std::endl;


	
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
