#include "miniRT.h"

// void	clamp(t_fcolor *frgb, float min, float max)
// {
// 	frgb->r = fmax(min, fmin(max, frgb->r));
// 	frgb->g = fmax(min, fmin(max, frgb->g));
// 	frgb->b = fmax(min, fmin(max, frgb->b));
// }

// void	apply_gamma(t_fcolor *frgb, float exposure, float gamma)
// {
// 	frgb->r = powf(frgb->r * exposure, gamma);
// 	frgb->g = powf(frgb->g * exposure, gamma);
// 	frgb->b = powf(frgb->b * exposure, gamma);
// }

void	rgb_eq(t_color *rgb1, t_color *rgb2)
{
	rgb1->r = rgb2->r;
	rgb1->g = rgb2->g;
	rgb1->b = rgb2->b;
}