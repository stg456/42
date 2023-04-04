/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:14:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/04 14:29:37 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <array>

class	PhoneBook
{
	private:
	std::string rep[8];
	int			lenC;
	int			numC;

	public:
	PhoneBook();
	void	add();
	void	search();
};

class	Contact
{
	private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DartkestSecret;

	public:
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