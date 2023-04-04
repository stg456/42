/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:06:16 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/04 16:38:43 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

	void            Contact::setFirstName(std::string firstName)
	{
		FirstName = firstName;
	}

    void            Contact::setLastName(std::string lastName)
	{
		LastName = lastName;
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
	