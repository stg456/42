/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:17:48 by stgerard          #+#    #+#             */
/*   Updated: 2023/01/16 12:19:44 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main ()
{
	int age(0);
	std::string nom("sans nom");
	// nom.
	std::cout << "Bonjour quel âge avez-vous?" << std::endl;
	std::cin >> age;
	std::cout << "Vous avez "<< age << " ans." << std::endl;

	getline(std::cin, nom);

	std::cout << "AU REVOIR" << std::endl;

	return 0;
}

// essai