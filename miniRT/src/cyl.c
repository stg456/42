/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:50:48 by stgerard          #+#    #+#             */
/*   Updated: 2023/08/16 14:24:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	check_cyl(t_cyl cy, t_data *d)
{
	if (vectinrange(cy.axe.x) || vectinrange(cy.axe.y) || vectinrange(cy.axe.z))
	{
		close(d->fd);
		ft_error("Error\norientation vector of cylinder not in the rang\n");
	}
	if (rgbinrange(cy.rgb.r) || rgbinrange(cy.rgb.g) || rgbinrange(cy.rgb.b)
		|| ft_isdigit(cy.rgb.r) || ft_isdigit(cy.rgb.g) || ft_isdigit(cy.rgb.b))
	{
		close(d->fd);
		ft_error("Error\nincorrect rgb value for cylinder\n");
	}
}

static void	init_matrice(float *matrice, t_cyl *cyl)
{
	matrice[2] = cyl->axe.x;
	matrice[5] = cyl->axe.y;
	matrice[8] = cyl->axe.z;
}

static void	build_matrice(float *matrice, t_cyl *cyl)
{
	t_vec	tmp;

	if (cyl->axe.x != 0 && cyl->axe.y != 0 && cyl->axe.z != 0)
		tmp = vec_init_fs(-cyl->axe.y / cyl->axe.x, 1.0f, 0.0f);
	else if (cyl->axe.x == 0 && cyl->axe.y != 0 && cyl->axe.z != 0)
		tmp = vec_init_fs(0.0f, -cyl->axe.z / cyl->axe.y, 1.0f);
	else if (cyl->axe.x != 0 && cyl->axe.y == 0 && cyl->axe.z != 0)
		tmp = vec_init_fs(1.0f, 0.0f, -cyl->axe.x / cyl->axe.z);
	else if (cyl->axe.x != 0 && cyl->axe.y != 0 && cyl->axe.z == 0)
		tmp = vec_init_fs(1.0f, -cyl->axe.x / cyl->axe.y, 0.0f);
	normalize(&tmp);
	matrice[1] = tmp.x;
	matrice[4] = tmp.y;
	matrice[7] = tmp.z;
	tmp = vec_init_fs(matrice[4] * matrice[8] - matrice[5] * matrice[7],
		matrice[1] * matrice[8] - matrice[2] * matrice[7],
		matrice[1] * matrice[5] - matrice[2] * matrice[4]);
	normalize(&tmp);
	matrice[0] = tmp.x;
	matrice[3] = tmp.y;
	matrice[6] = tmp.z;
}

static void	init_trans(float *trans, float *matrice)
{
	trans[0] = matrice[0];
	trans[1] = matrice[3];
	trans[2] = matrice[6];
	trans[3] = matrice[1];
	trans[4] = matrice[4];
	trans[5] = matrice[7];
	trans[6] = matrice[2];
	trans[7] = matrice[5];
	trans[8] = matrice[8];
}

static void	init_inv_matrice(float *inv_matrice, float *trans, float det)
{
	inv_matrice[0] = (trans[4] * trans[8] - trans[5] * trans[7]) / det;
	inv_matrice[1] = -((trans[3] * trans[8] - trans[5] * trans[6]) / det);
	inv_matrice[2] = (trans[3] * trans[7] - trans[4] * trans[6]) / det;
	inv_matrice[3] = -((trans[1] * trans[8] - trans[2] * trans[7]) / det);
	inv_matrice[4] = (trans[0] * trans[8] - trans[2] * trans[6]) / det;
	inv_matrice[5] = -((trans[0] * trans[7] - trans[1] * trans[6]) / det);
	inv_matrice[6] = (trans[1] * trans[5] - trans[4] * trans[2]) / det;
	inv_matrice[7] = -((trans[0] * trans[5] - trans[2] * trans[3]) / det);
	inv_matrice[8] = (trans[0] * trans[4] - trans[1] * trans[3]) / det;
}

static void	build_inv_matrice(float *matrice, t_cyl *cyl)
{
	float	det;
	float	trans[9];

	det = matrice[0] * (matrice[4] * matrice[8] - matrice[1] * matrice[5])
		- matrice[3] * (matrice[1] * matrice[8] - matrice[2] * matrice[7])
		+ matrice[6] * (matrice[1] * matrice[5] - matrice[2] * matrice[4]);
	init_trans(trans, matrice);
	init_inv_matrice(cyl->matrice, trans, det);
}

static void	matrice_cyl(t_cyl *cyl)
{
	float	matrice[9];

	init_matrice(matrice, cyl);
	build_matrice(matrice, cyl);
	build_inv_matrice(matrice, cyl);
}

t_vec	matrice_mult(float *matrice, t_vec *vec)
{
	t_vec	res;

	res.x = matrice[0] * vec->x + matrice[1] * vec->y + matrice[2] * vec->z;
	res.y = matrice[3] * vec->x + matrice[4] * vec->y + matrice[5] * vec->z;
	res.z = matrice[6] * vec->x + matrice[7] * vec->y + matrice[8] * vec->z;
	return (res);
}

static void	coor_swap1(t_cyl *cyl, t_data *d)
{
	float	swap;

	swap = cyl->axe.x;
	cyl->axe.x = cyl->axe.z;
	cyl->axe.z = cyl->axe.y;
	cyl->axe.y = swap;
	cyl->cam_pos = vecs_sus(&d->cam.pos, &cyl->pos); // before or after swap? (ask sensei)
	swap = d->cam.pos.x;
	cyl->cam_pos.x = d->cam.pos.z;
	cyl->cam_pos.z = d->cam.pos.y;
	cyl->cam_pos.y = swap;
	swap = d->cam.forward.x;
	cyl->cam_axe.x = d->cam.forward.z;
	cyl->cam_axe.z = d->cam.forward.y;
	cyl->cam_axe.y = swap;
}

static void	coor_swap2(t_cyl *cyl, t_data *d)
{
	float	swap;

	swap = cyl->axe.x;
	cyl->axe.x = cyl->axe.y;
	cyl->axe.y = cyl->axe.z;
	cyl->axe.z = swap;
	cyl->cam_pos = vecs_sus(&d->cam.pos, &cyl->pos); // before or after swap? (ask sensei)
	swap = d->cam.pos.x;
	cyl->cam_pos.x = d->cam.pos.y;
	cyl->cam_pos.y = d->cam.pos.z;
	cyl->cam_pos.z = swap;
	swap = d->cam.forward.x;
	cyl->cam_axe.x = d->cam.forward.y;
	cyl->cam_axe.y = d->cam.forward.z;
	cyl->cam_axe.z = swap;
}

static void	cyl_calc(t_cyl *cyl, t_data *d)
{
	if (cyl->axe.x == 0 && cyl->axe.y == 0 && cyl->axe.z != 0)
	{
		vec_eq(&cyl->cam_axe, &d->cam.forward);
		cyl->cam_pos = vecs_sus(&d->cam.pos, &cyl->pos);
	}
	else if (cyl->axe.x == 0 && cyl->axe.y != 0 && cyl->axe.z == 0)
		coor_swap1(cyl, d);
	else if (cyl->axe.x != 0 && cyl->axe.y == 0 && cyl->axe.z == 0)
		coor_swap2(cyl, d);
	else
	{
		matrice_cyl(cyl);
		cyl->new_coord = true;
		cyl->cam_pos = vecs_sus(&d->cam.pos, &cyl->pos);
		cyl->cam_pos = matrice_mult(cyl->matrice, &cyl->cam_pos);
		cyl->cam_axe = normalized(matrice_mult(cyl->matrice, &d->cam.forward));
	}
}

void	cyl(char *buf, t_data *d)
{
	t_cyl	cy;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;
	char	**tmpcolor;

	printf("dans cy: %s\n", buf);
	tmp = ft_split(buf, ' ');
	tmp_pos = ft_split(tmp[1], ',');
	cy.pos.x = ft_atof(tmp_pos[0]);
	cy.pos.y = ft_atof(tmp_pos[1]);
	cy.pos.z = ft_atof(tmp_pos[2]);
	tmp_axe = ft_split(tmp[2], ',');
	cy.axe.x = ft_atof(tmp_axe[0]);
	cy.axe.y = ft_atof(tmp_axe[1]);
	cy.axe.z = ft_atof(tmp_axe[2]);
	cy.radius = ft_atof(tmp[3]) / 2;
	cy.height = ft_atof(tmp[4]);
	tmpcolor = ft_split(tmp[5], ',');
	cy.rgb.r = ft_atoi(tmpcolor[0]);
	cy.rgb.g = ft_atoi(tmpcolor[1]);
	cy.rgb.b = ft_atoi(tmpcolor[2]);
	cy.frgb.r = ft_atof(tmpcolor[0]) / 255;
	cy.frgb.g = ft_atof(tmpcolor[1]) / 255;
	cy.frgb.b = ft_atof(tmpcolor[2]) / 255;
	cy.new_coord = false;
	printf("matrice: %f, %f, %f, %f, %f, %f, %f, %f, %f\n", cy.matrice[0], cy.matrice[1], cy.matrice[2], cy.matrice[3], cy.matrice[4], cy.matrice[5], cy.matrice[6], cy.matrice[7], cy.matrice[8]);
	free_all(tmp, tmp_pos, tmp_axe, tmpcolor);
	check_cyl(cy, d);
	cyl_calc(&cy, d);
	printf("matrice: %f, %f, %f, %f, %f, %f, %f, %f, %f\n", cy.matrice[0], cy.matrice[1], cy.matrice[2], cy.matrice[3], cy.matrice[4], cy.matrice[5], cy.matrice[6], cy.matrice[7], cy.matrice[8]);
	d->shapes.cylindres[d->nbcy - 1] = cy;
	d->nbcy--;
}
