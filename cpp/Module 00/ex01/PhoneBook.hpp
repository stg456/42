/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:14:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/07 12:32:31 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <array>
#include "Contact.hpp"

class	PhoneBook
{
	private:
	Contact 	rep[8];
	int			_lenC;
	int			_numC;
	int			_old;

	public:
	PhoneBook();
	void		add();
	void		search();
	void		printContact(int numb);
	void		printList(std::string str);
	std::string ft_cut(std::string str);
};

#endif