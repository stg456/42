/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:04:14 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/04 14:29:37 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add()
{
	std::string info[5];


	std::cout << "Fisrt Name:" ;
	std::getline(std::cin, info[0]);
	if (info[0].empty())
	{
		std::cout << "The fields of a registered contact cannot be empty!" << std::endl;
        return ;
	}
	std::cout << "Last Name:" ;
	std::getline(std::cin, info[1]);
	if (empty)
	{
	
	}
	std::cout << "Nick Name:" ;
	std::getline(std::cin, info[2]);
	if (empty)
	{
	
	}
	std::cout << "Phone Number:" ;
	std::getline(std::cin, info[3]);
	if (empty)
	{
	
	}
	std::cout << "Dartkest Secret:" ;
	std::getline(std::cin, info[4]);
	if (empty)
	{
	
	}
}

void	PhoneBook::search()
{
	std::cout << "enter the contact number you want:" ;
}