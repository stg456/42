/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:41:28 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/18 19:06:59 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	size_t			pos;
	std::string		str;
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::string		filename = av[1];
	std::ifstream	myfile (av[1], std::ios::binary | std::ios::in | std::ios::out);

	if (ac != 4)
	{
		std::cout << "Bad number of arguments !" << std::endl;
		return 1;
	}

	// if (s1.empty() || s2.empty())
	// {
	// 	std::cout << "Error in the arguments to replace !" << std::endl;
	// 	return 1;
	// }

	filename += ".replace"; //  creer le nom de fichier
	std::cout << filename << std::endl;

	std::ofstream newfile(filename, std::ios::binary | std::ios::out | std::ios::in);

	// if (newfile.is_open())
	// {
	// 	std::cout << "dans la boucle" << std::endl;
	// 	while (getline(myfile, filename, '\0'))
	// 	{
	// 		newfile << filename;
	// 		std::cout << filename << std::endl;
	// 	}
	// }

	// std::cout << myfile.is_open();
	
	if (myfile.is_open())
	{
		while (getline(myfile, str, '\0'))
		{
			// find, delete, insert
			newfile << str << std::endl; // mets le contenu dans le nouveau fichier
			std::cout << str << std::endl;
			str.find(s1);
			str.erase(s1);
			str.insert(s2);
		}
		
	}


	
	// myfile.close();
	
	return 0;	
}
