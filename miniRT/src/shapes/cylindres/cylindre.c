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

    if (cyl->new_coord == true)
    {
        ray_origin = vecs_sus(&inter->ray.pos, &cyl->pos);
        ray_origin = matrice_mult(cyl->matrice, &ray_origin);
        ray_direction = matrice_mult(cyl->matrice, &inter->ray.axe);
    }
    else
    {
        ray_origin = vecs_sus(&inter->ray.pos, &cyl->pos);
        ray_direction = inter->ray.axe;
    }
    // Calculate coefficients of the quadratic equation
    a = sqr(ray_direction.x) + sqr(ray_direction.y);
    b = ray_direction.x * ray_origin.x + ray_direction.y * ray_origin.y;
    c = sqr(ray_origin.x) + sqr(ray_origin.y) - sqr(cyl->radius);

    // Solve the quadratic equation
    discri = sqr(b) - a * c;

    if (discri < 0.0f || (discri == 0 && sqr(ray_direction.z * (-b / a) + ray_origin.z) > sqr(cyl->height / 2)))
        return (false); // No intersection
    else if (discri == 0)
        inter->t = -b / a;
    else
    {
        t1 = (-b - sqrt(discri)) / a; // First intersection point in local coordinate system
        t2 = (-b + sqrt(discri)) / a; // Second intersection point in local coordinate system

        // Check if t1 or if t2 is within valid range
	    if ((t1 > RAY_T_MIN && t1 < inter->t) && sqr(ray_direction.z * t1 + ray_origin.z) <= sqr(cyl->height / 2))
            inter->t = t1;
	    else if ((t2 > RAY_T_MIN && t2 < inter->t) && sqr(ray_direction.z * t2 + ray_origin.z) <= sqr(cyl->height / 2))
            inter->t = t2;
	    else
    	    return (false); // No intersection within the valid range
    }
    inter->pos = ray_calculate(&inter->ray, inter->t);
	inter->normal = normalized(vecs_sus(&inter->pos, &cyl->pos));
    inter->pShape = cyl;
    rgb_eq(&inter->rgb, &cyl->rgb);
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
