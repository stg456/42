#include "../../../inc/cylindre.h"

t_cyl	*cyl_init(t_vec *pos, t_vec *axe, float radius, float height)
{
	t_cyl	*cylindre;

	cylindre = malloc(sizeof(t_cyl));
	if (!cylindre)
		reurn (NULL);
	vec_eq(&cylindre->pos, pos);
	vec_eq(&cylindre->axe, axe);
	cylindre->radius = radius;
	cylindre->height = height;
	return (cylindre);
}

bool	cyl_intersect(t_cyl *cyl1, t_inter *inter1)
{
	
}

bool	cyl_doesintersect(t_cyl *cyl1, t_ray *ray1)
{

}
