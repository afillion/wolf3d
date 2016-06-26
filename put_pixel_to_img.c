#include "wolf.h"

void	put_pixel_to_img(t_env *e, double x, double y)
{
	int	pos;

	pos = (x * e->bpp / 8) + (y * e->size);
	e->data[pos] = e->color % 256;
	e->data[pos + 1] = (e->color >> 8) % 256;
	e->data[pos + 2] = (e->color >> 16) % 256;
}
