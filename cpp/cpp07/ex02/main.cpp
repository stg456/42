/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:49:57 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/06 11:30:42 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"
#include <ctime>

#define MAX_VAL 750

int main( void ) {
	Array<int> numbers(10);

	std::srand(static_cast<unsigned int>(std::time(0))); // Initialisez la graine avec le temps actuel.
	std::cout << "La taille du tableau est de " << numbers.size() << std::endl;
	std::cout << "Les valeurs aleatoires du tableau sont :" << std::endl;
	for (int i = 0; i < static_cast<int>(numbers.size()); i++) {
		numbers[i] = std::rand() % 100;
		std::cout << numbers[i] << std::endl;
	}
	std::cout << std::endl;
	Array<std::string> strings(5);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";
	strings[3] = "How";
	strings[4] = "are you?";
	std::cout << "La taille du tableau est de " << strings.size() << std::endl;
	std::cout << "Les valeurs du tableau sont :" << std::endl;
	for (int i = 0; i < static_cast<int>(strings.size()); i++) {
		std::cout << strings[i] << std::endl;
	}
	return (0);
}

//int main(int, char**)
//{
//    Array<int> numbers(MAX_VAL);
//    int* mirror = new int[MAX_VAL];
//    srand(time(NULL));
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        const int value = rand();
//        numbers[i] = value;
//        mirror[i] = value;
//    }
//    //SCOPE
//    {
//        Array<int> tmp = numbers;
//        Array<int> test(tmp);
//    }
//
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        if (mirror[i] != numbers[i])
//        {
//            std::cerr << "didn't save the same value!!" << std::endl;
//            return 1;
//        }
//    }
//    try
//    {
//        numbers[-2] = 0;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << '\n';
//    }
//    try
//    {
//        numbers[MAX_VAL] = 0;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << '\n';
//    }
//
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        numbers[i] = rand();
//    }
//    delete [] mirror;//
//    return 0;
//}