/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:14:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/03/25 14:56:51 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
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
	
};


#endif