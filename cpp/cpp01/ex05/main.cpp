/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:41:28 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/20 15:04:31 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	Harl;
	
	Harl.complain("error");
	Harl.complain("debug");
	Harl.complain("warning");
	Harl.complain("info");

	return 0;	
}
