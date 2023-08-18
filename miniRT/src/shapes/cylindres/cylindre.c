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

t_vec   cylray_origin(t_cyl * cyl, t_inter *inter)
{
    t_vec   ray_origin;

    if (cyl->new_coord == 0)
    {
        ray_origin = vecs_sus(&inter->ray.pos, &cyl->pos);
        ray_origin = matrice_mult(cyl->matrice, &ray_origin);
    }
     else if (cyl->new_coord == 1)
    {
        ray_origin = vecs_sus(&inter->ray.pos, &cyl->pos);
        ray_origin = coor_swap3(&ray_origin, 1);
    }
    else if (cyl->new_coord == 2)
    {
        ray_origin = vecs_sus(&inter->ray.pos, &cyl->pos);
        ray_origin = coor_swap3(&ray_origin, 2);
    }
    else
        ray_origin = vecs_sus(&inter->ray.pos, &cyl->pos);
    return (ray_origin);
}

t_vec   cylray_direction(t_cyl * cyl, t_inter *inter)
{
    t_vec   ray_direction;

    if (cyl->new_coord == 0)
        ray_direction = matrice_mult(cyl->matrice, &inter->ray.axe);
    else if (cyl->new_coord == 1)
        ray_direction = coor_swap3(&inter->ray.axe, 1);
    else if (cyl->new_coord == 2)
        ray_direction = coor_swap3(&inter->ray.axe, 2);
    else
        vec_eq(&ray_direction, &inter->ray.axe);
    return (ray_direction);
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

    ray_origin = cylray_origin(cyl, inter);
    ray_direction = cylray_direction(cyl, inter);
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
