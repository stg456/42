#include "miniRT.h"

void	clamp(t_fcolor *frgb, float min, float max)
{
	frgb->r = fmax(min, fmin(max, frgb->r));
	frgb->g = fmax(min, fmin(max, frgb->g));
	frgb->b = fmax(min, fmin(max, frgb->b));
}

void	apply_gamma(t_fcolor *frgb, float exposure, float gamma)
{
	frgb->r = powf(frgb->r * exposure, gamma);
	frgb->g = powf(frgb->g * exposure, gamma);
	frgb->b = powf(frgb->b * exposure, gamma);
}

t_fcolor	color_init(float r, float g, float b)
{
	t_fcolor	frgb;
	
	frgb.r = r;
	frgb.g = g;
	frgb.b = b;
	return (frgb);
}

t_fcolor	color_initf(float f)
{
	t_fcolor	frgb;
	
	frgb.r = f;
	frgb.g = f;
	frgb.b = f;
	return (frgb);
}
