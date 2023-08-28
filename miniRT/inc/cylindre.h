#ifndef CYLINDRE_H
# define CYLINDRE_H

typedef struct	s_lum	t_lum;
typedef struct	s_cyl
{
	t_vec		pos;
	t_vec		axe;
	float		radius;
	float		height;
	int			rgb;
	float		matrice[9];
	float		inv_matrice[9];
	int			new_coord;
	t_vec		cam_pos;
	t_vec		cam_axe;
}				t_cyl;

t_cyl	*cyl_init(t_vec *pos, t_vec *axe, float radius, float height);

bool	cyl_intersect(t_cyl *cyl, t_inter *inter);
bool	cyl_doesintersect(t_cyl *cyl, t_inter *inter);

t_vec   cylray_direction(t_cyl * cyl, t_ray *ray);
t_vec   cylray_origin(t_cyl * cyl, t_vec *raypos);

#endif