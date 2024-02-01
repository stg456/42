/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:17:48 by stgerard          #+#    #+#             */
/*   Updated: 2023/01/16 17:30:53 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

int main (int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (argc > 1)
	{
		for (size_t i = 1; argv[i]; i++)
		{
			std::string	str(argv[i]); 
			for (size_t j = 0; j < str.length(); j++)
			{
				str[j] = std::toupper(str[j]);
			}
			std::cout << str;
		}
	}
	std::cout << std::endl;
	return 0;
}
