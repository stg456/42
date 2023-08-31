#include "miniRT.h"

// t_cyl	*cyl_init(t_vec *pos, t_vec *axe, float radius, float height)
// {
// 	t_cyl	*cylindre;

// 	cylindre = malloc(sizeof(t_cyl));
// 	if (!cylindre)
// 		return (NULL);
// 	vec_eq(&cylindre->pos, pos);
// 	vec_eq(&cylindre->axe, axe);
// 	cylindre->radius = radius;
// 	cylindre->height = height;
// 	return (cylindre);
// }

// t_vec   cylray_origin(t_cyl * cyl, t_vec *raypos)
// {
//     t_vec   ray_origin;

//     if (cyl->new_coord == 0)
//     {
//         ray_origin = vecs_sus(raypos, &cyl->pos);
//         ray_origin = matrice_mult(cyl->inv_matrice, &ray_origin);
//     }
//      else if (cyl->new_coord == 1)
//     {
//         ray_origin = vecs_sus(raypos, &cyl->pos);
//         ray_origin = coor_swap3(&ray_origin, 1);
//     }
//     else if (cyl->new_coord == 2)
//     {
//         ray_origin = vecs_sus(raypos, &cyl->pos);
//         ray_origin = coor_swap3(&ray_origin, 2);
//     }
//     else
//         ray_origin = vecs_sus(raypos, &cyl->pos);
//     return (ray_origin);
// }

// // static t_vec   cylray_origin_inv(t_cyl *cyl, t_vec *raypos)
// // {
// //     t_vec   ray_origin;

// //     if (cyl->new_coord == 0)
// //     {
// //         ray_origin = matrice_mult(cyl->matrice, raypos);
// //         ray_origin = vecs_add(&ray_origin, &cyl->pos);
// //     }
// //      else if (cyl->new_coord == 1)
// //     {
// //         ray_origin = coor_swap_inv(raypos, 1);
// //         ray_origin = vecs_add(&ray_origin, &cyl->pos);
// //     }
// //     else if (cyl->new_coord == 2)
// //     {
// //         ray_origin = coor_swap_inv(raypos, 2);
// //         ray_origin = vecs_add(&ray_origin, &cyl->pos);
// //     }
// //     else
// //         ray_origin = vecs_add(raypos, &cyl->pos);
// //     return (ray_origin);
// // }

// t_vec   cylray_direction(t_cyl * cyl, t_ray *ray)
// {
//     t_vec   ray_direction;

//     if (cyl->new_coord == 0)
//         ray_direction = matrice_mult(cyl->inv_matrice, &ray->axe);
//     else if (cyl->new_coord == 1)
//         ray_direction = coor_swap3(&ray->axe, 1);
//     else if (cyl->new_coord == 2)
//         ray_direction = coor_swap3(&ray->axe, 2);
//     else
//         vec_eq(&ray_direction, &ray->axe);
//     return (ray_direction);
// }

// // static t_vec   cylray_direction_inv(t_cyl * cyl, t_vec *rayaxe)
// // {
// //     t_vec   ray_direction;

// //     if (cyl->new_coord == 0)
// //         ray_direction = matrice_mult(cyl->matrice, rayaxe);
// //     else if (cyl->new_coord == 1)
// //         ray_direction = coor_swap_inv(rayaxe, 1);
// //     else if (cyl->new_coord == 2)
// //         ray_direction = coor_swap_inv(rayaxe, 2);
// //     else
// //         vec_eq(&ray_direction, rayaxe);
// //     return (ray_direction);
// // }

// // static t_vec cyl_normal(t_cyl *cyl)
// // {
// //     t_vec	tmp;

// // 	if (cyl->axe.x != 0 && cyl->axe.y != 0 && cyl->axe.z != 0)
// // 		tmp = vec_init_fs(-cyl->axe.y / cyl->axe.x, 1.0f, 0.0f);
// // 	else if (cyl->axe.x == 0 && cyl->axe.y != 0 && cyl->axe.z != 0)
// // 		tmp = vec_init_fs(0.0f, -cyl->axe.z / cyl->axe.y, 1.0f);
// // 	else if (cyl->axe.x != 0 && cyl->axe.y == 0 && cyl->axe.z != 0)
// // 		tmp = vec_init_fs(1.0f, 0.0f, -cyl->axe.x / cyl->axe.z);
// // 	else if (cyl->axe.x != 0 && cyl->axe.y != 0 && cyl->axe.z == 0)
// // 		tmp = vec_init_fs(1.0f, -cyl->axe.x / cyl->axe.y, 0.0f);
// // 	normalize(&tmp);
// //     return (tmp);
// // }

// bool	cyl_intersect(t_cyl *cyl, t_inter *inter)
// {
//     t_ray   raycyl;
//     t_vec   normal;
// 	float	t1;
// 	float	t2;
// 	float	a;
// 	float	b;
// 	float	c;
// 	float	discri;
//     float   NdotR;

//     raycyl.pos = cylray_origin(cyl, &inter->ray.pos);
//     raycyl.axe = cylray_direction(cyl, &inter->ray);
//     // normal = cyl_normal(cyl); // to check
   
//     // Calculate coefficients of the quadratic equation
//     a = sqr(raycyl.axe.x) + sqr(raycyl.axe.y);
//     b = raycyl.axe.x * raycyl.pos.x + raycyl.axe.y * raycyl.pos.y;
//     c = sqr(raycyl.pos.x) + sqr(raycyl.pos.y) - sqr(cyl->radius);

//     // Solve the quadratic equation
//     discri = sqr(b) - a * c;

//     if (discri < 0.0f || (discri == 0 && sqr(raycyl.axe.z * (-b / a) + raycyl.pos.z) > sqr(cyl->height / 2)))
//         return (false); // No intersection
//     else if (discri == 0)
//         inter->t = -b / a;
//     else
//     {
//         t1 = (-b - sqrt(discri)) / a; // First intersection point in local coordinate system
//         t2 = (-b + sqrt(discri)) / a; // Second intersection point in local coordinate system

//         // Check if t1 or if t2 is within valid range
// 	    if ((t1 > RAY_T_MIN && t1 < inter->t) && sqr(raycyl.axe.z * t1 + raycyl.pos.z) <= sqr(cyl->height / 2))
//             inter->t = t1;
// 	    else if ((t2 > RAY_T_MIN && t2 < inter->t) && sqr(raycyl.axe.z * t2 + raycyl.pos.z) <= sqr(cyl->height / 2))
//             inter->t = t2;
// 	    else
//     	    return (false); // No intersection within the valid range
//     }
//     // raycyl.pos = cylray_origin_inv(cyl, &raycyl.pos);
//     // raycyl.axe = cylray_direction_inv(cyl, &raycyl.axe);
//     inter->pos = ray_calculate(&raycyl, inter->t);
//     NdotR = dot(inter->pos, normalized(cyl->axe));
//     normal = vecs_multf(&cyl->axe, NdotR);
// 	inter->normal = normalized(vecs_sus(&inter->pos, &normal));
//     inter->pShape = cyl;
//     inter->rgb = cyl->rgb;
// 	return (true);
// }

// bool	cyl_doesintersect(t_cyl *cyl, t_inter *inter)
// {
//     t_vec	ray_origin;
//     t_vec	ray_direction;
// 	float	t1;
// 	float	t2;
// 	float	a;
// 	float	b;
// 	float	c;
// 	float	discri;

//     ray_origin = cylray_origin(cyl, &inter->ray.pos);
//     ray_direction = cylray_direction(cyl, &inter->ray);
//     a = sqr(ray_direction.x) + sqr(ray_direction.y);
//     b = ray_direction.x * ray_origin.x + ray_direction.y * ray_origin.y;
//     c = sqr(ray_origin.x) + sqr(ray_origin.y) - sqr(cyl->radius);
//     discri = sqr(b) - a * c;
//     if (discri < 0.0f || (discri == 0 && sqr(ray_direction.z * (-b / a) + ray_origin.z) > sqr(cyl->height / 2)))
//         return (false);
//     else if (discri == 0)
//         return (true);
//     else
//     {
//         t1 = (-b - sqrt(discri)) / a;
// 	    if ((t1 > RAY_T_MIN && t1 < inter->t) && sqr(ray_direction.z * t1 + ray_origin.z) <= sqr(cyl->height / 2))
//             return (true);
//         t2 = (-b + sqrt(discri)) / a;
// 	    if ((t2 > RAY_T_MIN && t2 < inter->t) && sqr(ray_direction.z * t2 + ray_origin.z) <= sqr(cyl->height / 2))
//             return (true);
// 	    else
//     	    return (false);
//     }
// 	return (true);
// }