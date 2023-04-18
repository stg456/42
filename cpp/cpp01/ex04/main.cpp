/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:41:28 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/18 17:08:08 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	char			str[100];
	size_t			pos;
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::string		filename = av[1];
	std::ifstream	myfile (av[1], std::ios::binary | std::ios::out | std::ios::in);

	// if (ac != 4)
	// {
	// 	std::cout << "Bad number of arguments !" << std::endl;
	// 	return 1;
	// }

	// if (s1.empty() || s2.empty())
	// {
	// 	std::cout << "Error in the arguments to replace !" << std::endl;
	// 	return 1;
	// }


	// std::cout << filename << std::endl;
	std::string filename2 = filename; //  creer le nom de fichier
	filename2.append(".replace"); 


	std::ofstream newfile(filename2, std::ios::binary | std::ios::out | std::ios::in);

	if (newfile.is_open() && myfile.is_open())
	{
		// fstream 
		std::getline (myfile, filename2, '\0');
		// std::cout << myfile << std::endl;
		std::cout << filename << std::endl;
	}
	else
		std::cout << "pas dans la boucle" << std::endl;




	
	// myfile.close();
	
	return 0;	
}
