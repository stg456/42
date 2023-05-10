/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:34:18 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/10 14:49:15 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string Name);
	FragTrap(const FragTrap &copy);
	FragTrap& operator = (const FragTrap &rhs);
	~FragTrap();

	void	highFivesGuys(void);
};

#endif