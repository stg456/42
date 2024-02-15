/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:42:48 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/09 15:34:41 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{

	public:
	ScavTrap();
	ScavTrap(std::string Name);
	ScavTrap(const ScavTrap &copy);
	ScavTrap& operator = (const ScavTrap &rhs);
	~ScavTrap();

	void	attack(const std::string &target);
	void	guardGate();

	private:

};

#endif	