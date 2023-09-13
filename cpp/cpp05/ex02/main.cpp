/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:11:17 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/12 19:45:28 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void test1() {

        ShrubberyCreationForm	scf("form1");
		RobotomyRequestForm		rrf("form2");
		PresidentialPardonForm	prf("form3");
        Bureaucrat B1("Jim", 50);

    try {
        B1.signForm(scf);
		B1.executeForm(scf);
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;
    try {
        B1.signForm(rrf);
		B1.executeForm(rrf);
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;
    try {
        B1.signForm(prf);
		B1.executeForm(prf);
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;
}

int main() 
{
	std::cout << "___test1___" << std::endl;
	test1();

	return 0;
}
