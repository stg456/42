/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:41:28 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:22 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	std::string		str;
	std::string		buf;
	int 			i = 0;
	int				j = 0;
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::ifstream	myfile (av[1]);

	if (myfile.open())
	{
		while (getline(myfile, buf))
		{
			if ()
			{
			
			}
		}
	}
	else
		std::cout << "Impossible de lire le fichier !" << std::endl;




	myfile.close();
	return 0;	
}
