#include "wolf.h"

void	texel(t_env *e)
{
	e->tex_width = 256;
	e->texnum = e->world_map[e->map_x][e->map_y] - 1;
	if (e->side == 0)
		e->wall_x = e->ray_pos_y + e->d_ray * e->ray_dir_y;
	else
		e->wall_x = e->ray_pos_x + e->d_ray * e->ray_dir_x;
	e->wall_x -= floor((e->wall_x));
	e->tex_x = (int)(e->wall_x * e->tex_width);
	if (e->side == 0 && e->ray_dir_x > 0)
		e->tex_x = e->tex_width - e->tex_x - 1;
	if (e->side == 1 && e->ray_dir_y < 0)
		e->tex_x = e->tex_width - e->tex_x - 1;
}
