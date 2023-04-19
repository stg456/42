/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:41:28 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/19 16:44:11 by stgerard         ###   ########.fr       */
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
								std::cout << "a" << std::endl;
			str.erase(pos, s1.length()); // pb !
			std::cout << "a" << std::endl;
			str.insert(pos, s2);
			std::cout << str << std::endl;
				std::cout << "a" << std::endl;
		}	
	}

	std::string filename2 = filename + ".replace";
	std::ofstream newfile(filename2, std::ios::binary | std::ios::out | std::ios::in);
	
	if (newfile.is_open())
	{
		newfile << str << std::endl; // mets le contenu dans le nouveau fichier
	}
	std::cout << str << std::endl;

	// myfile.close();
	// newfile.close();
	
	return 0;	
}

// int	main(int argc, char **argv)
// {
// 	std::string str;
// 	std::string tmp;
// 	int		i;
// 	int		j;

// 	if (argc != 4)
// 		return (std::cout << "Error number arguments" << std::endl, 1);
// 	std::string s1 = argv[2];
// 	std::string s2 = argv[3];
// 	std::ifstream myfile (argv[1]);
// 	if (myfile.is_open())
// 	{
// 		while (getline(myfile, tmp))
// 		{
// 			str = str + tmp;
// 			str = str + '\n';
// 		}
// 		i = 0;
// 		while (str[i])
// 		{
// 			j = 0;
// 			while (s1[j] == str[i + j])
// 			{
// 				if (s1[j + 1] == '\0')
// 				{
// 					str.erase(i, s1.length());
// 					str.insert(i, s2);
// 				}
// 				j++;
// 			}
// 			i++;
// 		}
// 	}
// 	else
// 		std::cout << "Unable to read the file";
// 	std::string file_name = argv[1];
// 	file_name.append(".replace");
// 	std::ofstream myfile2 (file_name);
// 	if (myfile2.is_open())
// 	{
// 		myfile2 << str;
// 	}
// 	else
// 		std::cout << "unable to write in the file" << std::endl;
// 	return (0);
// }