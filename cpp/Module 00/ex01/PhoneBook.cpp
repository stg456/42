/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:04:14 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/04 15:59:20 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_lenC = 0;
	_numC = 0;
}

void	PhoneBook::add()
{
	std::string info[5];
	Contact		Contact;

	std::cout << "Fisrt Name:" ;
	std::getline(std::cin, info[0]);
	if (info[0].empty())
	{
		std::cout << "The fields of a registered contact cannot be empty!" << std::endl;
        return ;
	}
	contact[_numC].setFirstName(info[0]);

	std::cout << "Last Name:" ;
	std::getline(std::cin, info[1]);
	if (info[1].empty())
	{
		std::cout << "The fields of a registered contact cannot be empty!" << std::endl;
        return ;
	}
	contact[_numC].setLastName(info[1]);

	std::cout << "Nick Name:" ;
	std::getline(std::cin, info[2]);
	if (info[2].empty())
	{
		std::cout << "The fields of a registered contact cannot be empty!" << std::endl;
        return ;
	}
	contact[_numC].setPhoneNumber(info[2]);

	std::cout << "Phone Number:" ;
	std::getline(std::cin, info[3]);
	if (info[3].empty())
	{
		std::cout << "The fields of a registered contact cannot be empty!" << std::endl;
        return ;
	}
	contact[_numC].setNickName(info[3]);

	std::cout << "Dartkest Secret:" ;
	std::getline(std::cin, info[4]);
	if (info[4].empty())
	{
		std::cout << "The fields of a registered contact cannot be empty!" << std::endl;
        return ;
	}
	contact[_numC].setDarkestSecret(info[4]);
}

void	PhoneBook::search()
{
	std::cout << "enter the contact number you want:" ;
}