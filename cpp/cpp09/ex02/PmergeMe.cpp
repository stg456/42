/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:42:10 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/30 11:14:33 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &src) {
	*this = src;
}

PmergeMe::~PmergeMe() {}


PmergeMe & PmergeMe::operator = (PmergeMe const &rhs) {
	if (this != &rhs) {
		_vector = rhs._vector;
		_deque = rhs._deque;
	}
	return *this;
}


int PmergeMe::check(char *str) {
	int i = 0;

	while (str[i]) {
		if (isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

void PmergeMe::insert(char **av) {
	int i = 1;

	while (av[i]) {
		_vector.push_back(atoi(av[i]));
		i++;
	}

	while (av[i]) {
		_deque.push_back(atoi(av[i]));
		i++;
	}
}

void PmergeMe::print(int ac, char **av) {
// Sur la première ligne, vous devez afficher un texte explicite suivi du positif non trié
// séquence entière
// Sur la deuxième ligne, vous devez afficher un texte explicite suivi du positif trié
// séquence entière.
// Sur la troisième ligne, vous devez afficher un texte explicite indiquant l’heure utilisée par
// votre algorithme en spécifiant le premier conteneur utilisé pour trier l’entier positif
// séquence
// Sur la dernière ligne, vous devez afficher un texte explicite indiquant l’heure utilisée par
// votre algorithme en spécifiant le second conteneur utilisé pour trier l’entier positif
// séquence
// Le format pour l’affichage du temps utilisé pour effectuer votre tri
// est libre mais la précision choisie doit permettre de
// différence entre les deux contenants utilisés

	
	std::cout << "Before: ";
	for (int i = 1; i <= ac; i++) {
		std::cout << av[i];
		// std::cout << _vector[i] << std::endl;
		// std::cout << _deque[i] << std::endl;
	}
	std::cout << std::endl;

	std::clock_t start1 = std::clock();
	std::sort(_vector.begin(), _vector.end());
	std::clock_t end1 = std::clock();
	
	std::clock_t start2 = std::clock();
	std::sort(_deque.begin(), _deque.end());
	std::clock_t end2 = std::clock();
	
	std::cout << "After: ";
	std::vector<int>::iterator it = _vector.begin();


	while (it != _vector.end()) {
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << "Time: " << (end1 - start1) * 1000 << std::endl;
	std::cout << "Time: " << (end2 - start2) * 1000 << std::endl;
}