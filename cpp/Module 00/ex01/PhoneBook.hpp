/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:14:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/03/22 17:21:54 by stgerard         ###   ########.fr       */
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
	std::string rep[8];
};

class	Contact
{
	std::string FirsName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DartkestSecret;
};

// template <typename T>
// {

// }

// PhoneBook.cpp

int		main(void);

#endif