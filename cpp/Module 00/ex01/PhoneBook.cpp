/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:04:14 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/07 12:32:31 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _lenC(0), _numC(0), _old(0) {}

void	PhoneBook::add()
{
	std::string info[5];

	while (info[0].empty())
	{
		std::cout << "Fisrt Name:" ;
		std::getline(std::cin, info[0]);
	}
	while (info[1].empty())
	{
		std::cout << "Last Name:" ;
		std::getline(std::cin, info[1]);
	}
	while (info[2].empty())
	{
		std::cout << "Nick Name:" ;
		std::getline(std::cin, info[2]);
	}
	while (info[3].empty())
	{
		std::cout << "Phone Number:" ;
		std::getline(std::cin, info[3]);
	}
	while (info[4].empty())
	{
		std::cout << "Darkest Secret:" ;
		std::getline(std::cin, info[4]);
	}
	rep[_numC].setContact(info);
	this->_old++;
	if (this->_old >= 16)
		this->_old = 8;
	if (_old >= 8)
		_numC = _old - 8;
	else
		_numC++;
}

void PhoneBook::printContact(int numb)
{
	numb -= 1;
	std::cout << this->rep[numb].getFirstName() << std::endl;
	std::cout << this->rep[numb].getLastName() << std::endl;
	std::cout << this->rep[numb].getPhoneNumber() << std::endl;
	std::cout << this->rep[numb].getNickName() << std::endl;
	std::cout << this->rep[numb].getDarkestSecret() << std::endl;
}

std::string PhoneBook::ft_cut(std::string str)
{
	if (str.length() < 10)
	{
		int a = 10 - str.length();
		std::string txt = "          ";
		// std::string txt = str.substr(0, a);
		txt.insert(a, str);
		return (txt);
	}
	else
	{
		std::string txt = str.substr(0, 9);
		txt.insert(9, ".");
		return (txt);
	}
}

void	PhoneBook::printList(std::string str)
{
	int space = 0;
	// _lenC
	// _numC
	std::cout << "|     index|First Name| Last Name| Nick Name|" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	for (_numC = 0; _numC <= 8; _numC++)
	{

	}
	
}

void	PhoneBook::search()
{
	int checker;
	std::string ct_numb;
	// this->printlist();
	std::cout << "enter the contact number you want:";
	std::getline(std::cin, ct_numb);
	checker = stoi(ct_numb);
	if (checker < 1 || checker > 8)
	{
		std::cout << "invalid number of contact" << std::endl;
		return ;
	}
	this->printContact(std::stoi(ct_numb));
}
