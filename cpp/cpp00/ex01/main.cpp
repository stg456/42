/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:12:15 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/07 18:30:32 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	phoneBook;

	std::cout << "enter ADD or SEARCH or EXIT" << std::endl;
	while (42)
	{
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			phoneBook.add();
		else if (cmd == "SEARCH")
			phoneBook.search();
		else if (cmd == "EXIT")
			exit (0);
		else
			std::cout << "Invalid command !";
			std::cout << std::endl;
	}
	return 0;
}

/*jump into c++ , alex Allain
practice c++ , o'reilly*/