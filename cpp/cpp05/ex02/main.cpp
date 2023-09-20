/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:11:17 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/20 12:58:30 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void test() {

        ShrubberyCreationForm	shrub("formulaire de création de Shrubbery");
		RobotomyRequestForm		robot("formulaire de robotomysation");
		PresidentialPardonForm	presid("formulaire de pardon présidentiel");
        Bureaucrat B1("Jim", 155);	// 145 to sign, 137 to execute
		Bureaucrat B2("Jess", 40);	// 72 to sign, 45 to execute
		Bureaucrat B3("Jack", 5);	// 25 to sign, 5 to execute

    try {
        B1.signForm(shrub);
		// B1.signForm(shrub);
		B1.executeForm(shrub);
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;
    try {
        B2.signForm(robot);
		B2.executeForm(robot);
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;
    try {
        B3.signForm(presid);
		B3.executeForm(presid);
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;
}

int main() 
{
	std::cout << "___test___" << std::endl;
	test();

	return 0;
}
