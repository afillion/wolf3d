#include "wolf.h"

void	put_pixel_to_img(t_env *e, double x, double y)
{
	int	pos;

	pos = (x * e->bpp / 8) + (y * e->size);
	e->data[pos] = e->color % 256;
	e->data[pos + 1] = (e->color >> 8) % 256;
	e->data[pos + 2] = (e->color >> 16) % 256;
}

void	color(t_env *e, double y)
{
	e->color = 0xFFFFFF;
	if (e->world_map[e->map_x][e->map_y] == 1)
		e->color = 0xFF0000;
	if (e->world_map[e->map_x][e->map_y] == 2)
		e->color = 0x00FF00;
	if (e->world_map[e->map_x][e->map_y] == 3)
		e->color = 0x0000FF;
	if (e->world_map[e->map_x][e->map_y] == 4)
		e->color = 0xFFFF00;
	if (e->side == 1)
		e->color = e->color / 2;
	if (y < e->start)
		e->color = 0x00FFFF;
	if (y > e->end)
		e->color = 0xFFCC99;
}
