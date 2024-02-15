/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:06:16 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/05 19:29:08 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::setContact(std::string info[5])
{
	FirstName = info[0];
	LastName = info[1];
	NickName = info[2];
	PhoneNumber = info[3];
	DarkestSecret = info[4];
	return ;
}

Contact::Contact()
{
}

void            Contact::setFirstName(std::string firstName)
{
	this->FirstName = firstName;
}

void            Contact::setLastName(std::string lastName)
{
	this->LastName = lastName;
}

void            Contact::setPhoneNumber(std::string phoneNumber)
{
	PhoneNumber = phoneNumber;
}

void            Contact::setNickName(std::string nickName)
{
	NickName = nickName;
}

void            Contact::setDarkestSecret(std::string darkestSecret)
{
	DarkestSecret = darkestSecret;
}

std::string    Contact::getFirstName()
{
	return (FirstName);
}

std::string     Contact::getLastName()
{
	return (LastName);
}

std::string     Contact::getPhoneNumber()
{
	return (PhoneNumber);
}

std::string     Contact::getDarkestSecret()
{
	return (DarkestSecret);
}

std::string     Contact::getNickName()
{
	return (NickName);
}
	