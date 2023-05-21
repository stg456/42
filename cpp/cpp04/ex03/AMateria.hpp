/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:25:11 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/21 17:48:22 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &copy);
		AMateria& operator = (const AMateria &rhs);
		virtual ~AMateria();

		std::string const	& getType() const;
		virtual			AMateria* clone() const = 0;
		virtual void	use(ICharacter & target);
};

class Ice
{
	private:
		std::string	ice;

	public:
		Ice();
		Ice(std::string const &type);
		Ice(const Ice &copy);
		Ice& operator = (const Ice &rhs);
		~Ice();
};

class Cure
{
	private:
		std::string	cure;

	public:
		Cure();
		Cure(std::string const &type);
		Cure(const Cure &copy);
		Cure operator = (const Cure &rhs);
		~Cure();
};

class Character
{
	public:
		ICharacter();
		ICharacter(std::string const &name);
		ICharacter(const ICharacter &copy);
		ICharacter& operator = (const ICharacter &rhs);
		virtual ~ICharacter();

		virtual std::string const & getName() const = 0;
		virtual void	equip(AMateria* m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter &target) = 0;
};

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif