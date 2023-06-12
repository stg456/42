/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:44:25 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/12 17:50:27 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rgbinrange(int nb)
{
	if (nb < 0 || nb > 255)
		return (1);
	return (0);
}

int	vectinrange(double nb)
{
	if (nb < -1 || nb > 1)
		return (1);
	return (0);
}

int	ratioinrange(double nb)
{
	if (nb < 0 || nb > 1)
		return (1);
	return (0);
}

void	check(t_env e, int ac, char **av)
{
	(void)e;
	t_amb	a;
	// t_lum	l;
	// t_pl	pl;
	// t_sp	sp;
	// t_cy	cy;
	// t_cam	c;

	if (ac != 2)
		ft_error("\x1B[31mError\nBad number of arguments\n");
	else if (ft_strnstr(av[1], ".rt", ft_strlen(av[1])) == NULL)
		ft_error("\x1B[31mError\nmap has to be .rt\n");
	else if (rgbinrange(a.rgb.r) || rgbinrange(a.rgb.g) || rgbinrange(a.rgb.b)
			/*|| rgbinrange(l.rgb.r) || rgbinrange(l.rgb.g) || rgbinrange(l.rgb.b)
			|| rgbinrange(pl.rgb.r) || rgbinrange(pl.rgb.g) || rgbinrange(pl.rgb.b)
			|| rgbinrange(sp.rgb.r) || rgbinrange(sp.rgb.g) || rgbinrange(sp.rgb.b)
			|| rgbinrange(cy.rgb.r) || rgbinrange(cy.rgb.g) || rgbinrange(cy.rgb.b)*/)
		ft_error("Error\nincorrect color in an element\n");
	// else if (vectinrange(c.axe.x) || vectinrange(c.axe.y) || vectinrange(c.axe.z)
	// 		|| vectinrange(pl.axe.x) || vectinrange(pl.axe.y) || vectinrange(pl.axe.z)
	// 		|| vectinrange(cy.axe.x) || vectinrange(cy.axe.y) || vectinrange(cy.axe.z))
	// 	ft_error("Error\nincorect vector\n");
	// else if (ratioinrange(l.ratioL) || ratioinrange(a.ratioA))
	// 	ft_error("Error\nincorect ratio\n");
}
// pb sur les check color et vector