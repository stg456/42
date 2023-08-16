#ifndef CYLINDRE_H
# define CYLINDRE_H

typedef struct	s_cyl
{
	t_vec		pos;
	t_vec		axe;
	float		radius;
	float		height;
	t_color		rgb;
	t_fcolor	frgb;
	float		matrice[9];
	bool		new_coord;
	t_vec		cam_pos;
	t_vec		cam_axe;
}				t_cyl;

t_cyl	*cyl_init(t_vec *pos, t_vec *axe, float radius, float height);

bool	cyl_intersect(t_cyl *cyl, t_inter *inter);
bool	cyl_doesintersect(t_cyl *cyl, t_ray *ray);

#endif