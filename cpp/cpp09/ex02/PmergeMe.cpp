/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:42:10 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/30 09:36:00 by stgerard         ###   ########.fr       */
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


bool PmergeMe::check(char *str) {
	int i = 0;

	while (str[i]) {
		if (isdigit(str[i]))
			return true;
		i++;
	}
	return false;
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

void PmergeMe::print(int ac) {
Sur la première ligne, vous devez afficher un texte explicite suivi du positif non trié
séquence entière
Sur la deuxième ligne, vous devez afficher un texte explicite suivi du positif trié
séquence entière.
Sur la troisième ligne, vous devez afficher un texte explicite indiquant l’heure utilisée par
votre algorithme en spécifiant le premier conteneur utilisé pour trier l’entier positif
séquence
Sur la dernière ligne, vous devez afficher un texte explicite indiquant l’heure utilisée par
votre algorithme en spécifiant le second conteneur utilisé pour trier l’entier positif
séquence
Le format pour l’affichage du temps utilisé pour effectuer votre tri
est libre mais la précision choisie doit permettre de
différence entre les deux contenants utilisés

	std::vector<int>::iterator it = _vector.begin();
	ac = ac - 1;

	while (it != _vector.end()) {
		std::cout << *it << std::endl;
		it++;
	}
}