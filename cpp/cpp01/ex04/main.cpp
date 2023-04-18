/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:41:28 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/18 15:59:21 by stgerard         ###   ########.fr       */
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
	std::ifstream	myfile (av[1]);

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

	filename.append(".replace"); // creer le nom de fichier
	std::cout << filename << std::endl;

	std::ofstream newfile(filename, std::ios::binary);
	while (str)
	{
		filename << str;
	}




	// std::cout << str << std::endl;

	


	// myfile.close();
	
	return 0;	
}
