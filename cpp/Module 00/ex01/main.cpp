/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:12:15 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/04 16:04:00 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	phoneBook;
	Contact		Contact;

	while (42)
	{
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			PhoneBook.add();
		else if (cmd == "SEARCH")
			PhoneBook.search();
		else if (cmd == "EXIT")
			exit (0);
		else
			std::cout << "Invalid command !";
		return (0);
	}
	

	return 0;
}