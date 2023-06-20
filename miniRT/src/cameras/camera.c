#include "../../inc/camera.h"

t_cam	*cam_init(t_vec pos, t_vec forward, t_vec upguide, int fov, float aspect_ratio)
{
	t_cam	*camera;

	camera = malloc(sizeof(t_cam));
	if (!camera)
		return (NULL);
	camera->pos = pos;
	camera->forward = forward;
	camera->right = normalized(cross(forward, upguide));
	camera->up = cross(camera->right, forward);
	h = tan(fov);
	w = h * aspect_ratio;
	return (camera);
}

t_ray	make_ray(t_cam *cam, t_vec2	point)
{
	t_vec	*axe;
	t_ray	ray;

	axe = cam->forward + point.u * cam->w * cam->right + point.v * cam->h * cam->up;
	ray.pos = cam->pos;
	ray.axe = normalized(&axe);
	ray.tMAX = RAY_T_MAX;
	return (ray);
}
