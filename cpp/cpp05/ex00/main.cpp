/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:11:17 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/06 10:19:46 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test1() {
	try 
	{
		Bureaucrat B1("Jim", 10);
		Bureaucrat B2("Joe", 20);
		// Bureaucrat B3("John", 200);
		// Bureaucrat B4("Jess", 1);
		Bureaucrat B5;
		std::cout << B1;
		std::cout << B2;
		// std::cout << B3;
		// std::cout << B4;
		B5 = B2;
		std::cout << B5;
	}
	catch (std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
	}
}

void test2() {
	try 
	{
		// Bureaucrat B1("Jim", 10);
		Bureaucrat B2("Joe", 20);
		Bureaucrat B3("John", 200);
		// Bureaucrat B4("Jess", 1);
		Bureaucrat B5;
		// std::cout << B1;
		std::cout << B2;
		std::cout << B3;
		// std::cout << B4;
		B5 = B2;
		std::cout << B5;
	}
	catch (std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
	}	
}

void test3() {
	try 
	{
		// Bureaucrat B1("Jim", 10);
		Bureaucrat B2("Joe", 20);
		// Bureaucrat B3("John", 200);
		Bureaucrat B4("Jess", 0);
		Bureaucrat B5;
		// std::cout << B1;
		std::cout << B2;
		// std::cout << B3;
		std::cout << B4;
		B5 = B2;
		std::cout << B5;
	}
	catch (std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
	}	
}

int main() 
{
	std::cout << "___test1___" << std::endl;
	test1();
	std::cout << "___test2___" << std::endl;
	test2();
	std::cout << "___test3___" << std::endl;
	test3();
	
	return 0;
}