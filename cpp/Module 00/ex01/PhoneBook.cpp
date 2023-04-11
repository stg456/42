/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:04:14 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/11 15:30:11 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _numC(0), _old(0) {}

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
	std::cout << "First Name: " << this->rep[numb].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->rep[numb].getLastName() << std::endl;
	std::cout << "Nic kName: " << this->rep[numb].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->rep[numb].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->rep[numb].getDarkestSecret() << std::endl;
}

std::string PhoneBook::ft_cut(std::string str)
{
	if (str.length() < 10)
		return (str);
	else
	{
		std::string txt = str.substr(0, 9);
		txt.insert(9, ".");
		return (txt);
	}
}

void	PhoneBook::printList(std::string str)
{
	PhoneBook phonebook;

	std::cout << "|     index|First Name| Last Name| Nick Name|" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	for (int i = 1; i <= 8; i++)
	{
		std::string FirstName = this->rep[_numC - 1].getFirstName();
		std::string LastName = this->rep[_numC - 1].getLastName();
		std::string NickName = this->rep[_numC - 1].getNickName();
		std::cout << "|" << std::setw(10) << _numC << "|" << std::setw(10) << phonebook.ft_cut(FirstName) << "|" << std::setw(10) << phonebook.ft_cut(LastName) << "|" << std::setw(10) << phonebook.ft_cut(NickName) << "|" << std::endl;
	}
	std::cout << "|___________________________________________|" << std::endl;
}

void	PhoneBook::search()
{
	int checker;
	std::string ct_numb;
	this->printList(ct_numb);
	while (ct_numb.empty() || (ct_numb[0] < '1' || ct_numb[0] > '8') || (ct_numb.length() > 1))
	{
		std::cout << "enter the contact number you want:";
		getline(std::cin, ct_numb);
	}
	printContact(std::stoi(ct_numb));
}
