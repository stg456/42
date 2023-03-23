/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:04:14 by stgerard          #+#    #+#             */
/*   Updated: 2023/03/23 16:52:56 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	cmd;

	while (42)
	{
		getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			getline(std::cin, FirstName);
			std::cin >> Contact.FirsName;
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
	}
	

	return 0;
}