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
}				t_cyl;

t_cyl	*cyl_init(t_vec *pos, t_vec *axe, float radius, float height);

bool	cyl_intersect(t_cyl *cyl1, t_inter *inter1);
bool	cyl_doesintersect(t_cyl *cyl1, t_ray *ray1);

#endif