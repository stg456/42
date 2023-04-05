/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:56:25 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/05 19:25:12 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <array>

class	Contact
{
	private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;

	public:
	void setContact(std::string info[5]);
	Contact();
	void            setFirstName(std::string firstName);
    void            setLastName(std::string lastName);
    void            setPhoneNumber(std::string phoneNumber);
    void            setNickName(std::string nickName);
    void            setDarkestSecret(std::string darkestSecret);
    std::string     getFirstName();
    std::string     getLastName();
    std::string     getPhoneNumber();
    std::string     getDarkestSecret();
    std::string     getNickName();
};

#endif