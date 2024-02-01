/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:37 by stgerard          #+#    #+#             */
/*   Updated: 2023/11/01 14:48:21 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

int main(int ac, char **av) {
	if (ac != 3) {
		std::cerr << "Error: arguments required" << std::endl;
		return 1;
	}
	Server irc;
	irc.set_port(av[1]);
	irc.set_password(av[2]);
	irc.run();
	

	return 0;
}
