/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:04:14 by stgerard          #+#    #+#             */
/*   Updated: 2023/03/22 17:21:54 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	cmd;

	getline(std::cin, cmd);
	if (std::cin >> ADD)
	{
		std::cin >> FirsName;
		std::cin >> LastName;
		std::cin >> NickName;
		std::cin >> PhoneNumber;
		std::cin >> DartkestSecret;
	}
	else if (cmd == "SEARCH")
	{
		;
	}
	else if (cmd == "EXIT")
	{
		std::cin.clear();
		return 0;
	}
	

	// new contact

	return 0;
}