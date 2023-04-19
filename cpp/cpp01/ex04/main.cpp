/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:41:28 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/19 16:00:36 by stgerard         ###   ########.fr       */
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
	std::string		filename;
	std::ifstream	myfile (av[1], std::ios::binary | std::ios::in | std::ios::out);

	if (ac != 4)
	{
		std::cout << "Bad number of arguments !" << std::endl;
		exit (0);
	}
	filename = av[1]; // apres la protection sinon seg fault
	
	// if (s1.empty() || s2.empty())
	// {
	// 	std::cout << "Error in the arguments to replace !" << std::endl;
	// 	return 1;
	// }

	std::cout << str << std::endl;

	if (myfile.is_open())
	{
		while (getline(myfile, str, '\0'))
		{
			pos = str.find(s1);
			std::cout << pos << std::endl;
			str.erase(pos, s1.length());
			str.insert(pos, s2);
			std::cout << str << std::endl;
		}	
	}

	std::string filename2 = filename + ".replace";
	std::ofstream newfile(filename2, std::ios::binary | std::ios::out | std::ios::in);
	
	if (newfile.is_open())
	{
		newfile << str << std::endl; // mets le contenu dans le nouveau fichier
	}
	std::cout << str << std::endl;

	myfile.close();
	newfile.close();
	
	return 0;	
}
