/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:41:28 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/21 14:46:47 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	size_t			i = 0;
	std::string		str;
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::string		filename;
	std::ifstream	myfile (av[1], std::ios::binary | std::ios::in | std::ios::out);

	if (ac != 4)
	{
		std::cout << "Bad number of arguments !" << std::endl;
		exit (0);
	}

	if (s1.empty() || s2.empty())
	{
		std::cout << "Error in the arguments to replace !" << std::endl;
		exit (0);
	}

	if (myfile.is_open())
	{
		while (getline(myfile, str, '\0'))
		{
			i = str.find(s1); // il manque une protection si av[2] n'est pas present dans av[1]
			while (i != str.npos) // si different ca veux dire qu'il a trouve le str
			{
				str.erase(i, s1.length());
				str.insert(i, s2);
				i = str.find(s1); // il manque une protection si av[2] n'est pas present dans av[1]
			}

			// std::cout << str[i] << std::endl;
				// std::cout << "Error the arument to replace is not present !" << std::endl;
				// exit (0);
			std::cout << str << std::endl;
		}
	}

	filename = av[1]; // apres la protection sinon seg fault
	std::string filename2 = filename + ".replace";
	// std::cout << filename2 << std::endl;
	
	std::ofstream newfile(filename2, std::ios::binary | std::ios::out);
	if (newfile.is_open())
	{
		// std::cout << "is open" << std::endl;
		newfile << str; // mets le contenu dans le nouveau fichier
	}

	myfile.close();
	newfile.close();
	
	return 0;	
}
