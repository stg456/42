#include "miniRT.h"

t_cyl	*cyl_init(t_vec *pos, t_vec *axe, float radius, float height)
{
	t_cyl	*cylindre;

	cylindre = malloc(sizeof(t_cyl));
	if (!cylindre)
		return (NULL);
	vec_eq(&cylindre->pos, pos);
	vec_eq(&cylindre->axe, axe);
	cylindre->radius = radius;
	cylindre->height = height;
	return (cylindre);
}

bool	cyl_intersect(t_cyl *cyl, t_inter *inter)
{
    t_vec	ray_origin;
    t_vec	ray_direction;
	float	t1;
	float	t2;
	float	a;
	float	b;
	float	c;
	float	discri;

	ray_origin = vecs_sus(&inter->ray.pos, &cyl->pos);
	vec_eq(&ray_direction, &inter->ray.axe);

    // Calculate coefficients of the quadratic equation
    a = length2(&ray_direction) - sqr(dot(ray_direction, cyl->axe));
    b = 2 * (dot(ray_direction, ray_origin) - dot(ray_direction, cyl->axe) * dot(ray_origin, cyl->axe));
    c = length2(&ray_origin) - sqr(dot(ray_origin, cyl->axe)) - sqr(cyl->radius);

    // a = dot(cyl->cam_axe, vec_init_fs(0, 1, 0));
    // b = 

    // Solve the quadratic equation
    discri = sqr(b) - 4 * a * c;

    if (discri < 0.0f)
        return (false); // No intersection

    t1 = (-b - sqrt(discri)) / (2 * a); // First intersection point in local coordinate system
    t2 = (-b + sqrt(discri)) / (2 * a); // Second intersection point in local coordinate system

    // Check if t1 is within valid range
	if ((t1 > RAY_T_MIN && t1 < inter->t) && sqr(t1) <= (sqr(cyl->height / 2) + length2(&ray_origin)) && sqr(t1) >= -(sqr(cyl->height / 2) + length2(&ray_origin)))
        inter->t = t1;
	else if ((t2 > RAY_T_MIN && t2 < inter->t) && sqr(t2) <= (sqr(cyl->height / 2) + length2(&ray_origin)) && sqr(t2) >= -(sqr(cyl->height / 2) + length2(&ray_origin)))
        inter->t = t2;
	else
	{
		// printf("t1 = %f, t2 = %f\n", t1, t2);
    	return (false); // No intersection within the valid range
	}
    inter->pShape = cyl;
    rgb_eq(&inter->rgb, &cyl->rgb);
    // printf("frgb: %f, %f, %f\n", inter->frgb.r, inter->frgb.g, inter->frgb.b);
	// printf("SUCCESS:\nt1 = %f, t2 = %f\n", t1, t2);
	return (true);
}

bool	cyl_doesintersect(t_cyl *cyl, t_ray *ray)
{
    t_vec	ray_origin;
    t_vec	ray_direction;
	float	t1;
	float	t2;
	float	a;
	float	b;
	float	c;
	float discri;

	ray_origin = vecs_sus(&ray->pos, &cyl->pos);
	ray_direction = ray->axe;

    // Calculate coefficients of the quadratic equation
    a = length2(&ray_direction) - sqr(dot(ray_direction, cyl->axe));
    b = 2 * (dot(ray_direction, ray_origin) - dot(ray_direction, cyl->axe) * dot(ray_origin, cyl->axe));
    c = length2(&ray_origin) - sqr(dot(ray_origin, cyl->axe)) - sqr(cyl->radius);

    // Solve the quadratic equation
    discri = sqr(b) - 4 * a * c;

    if (discri < 0.0f)
        return (false); // No intersection

    t1 = (-b - sqrt(discri)) / 2 * a; // First intersection point in local coordinate system
    t2 = (-b + sqrt(discri)) / 2 * a; // Second intersection point in local coordinate system

    // Check if t1 is within valid range
    if (t1 >= (-cyl->height / 2) && t1 <= (cyl->height / 2))
        return (true);
    // Check if t2 is within valid range
    else if (t2 >= (-cyl->height / 2) && t2 <= (cyl->height / 2))
        return (true);
    return (false); // No intersection within the valid range
}
