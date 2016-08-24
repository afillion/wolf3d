#include "wolf.h"

void	get_way_and_dist(t_env *e)
{
	if (e->ray_dir_x < 0)
	{
		e->way_x = -1;
		e->d_x = (e->ray_pos_x - e->map_x) * e->x_a;
	}
	else
	{
		e->way_x = 1;
		e->d_x = (e->map_x + 1.0 - e->ray_pos_x) * e->x_a;
	}
	if (e->ray_dir_y < 0)
	{
		e->way_y = -1;
		e->d_y = (e->ray_pos_y - e->map_y) * e->y_a;
	}
	else
	{
		e->way_y = 1;
		e->d_y = (e->map_y + 1.0 - e->ray_pos_y) * e->y_a;
	}
}

void	dda_algo(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->d_x < e->d_y)
		{
			e->d_x += e->x_a;
			e->map_x += e->way_x;
			e->side = 0;
		}
		else
		{
			e->d_y += e->y_a;
			e->map_y += e->way_y;
			e->side = 1;
		}
		if (e->world_map[e->map_x][e->map_y] > 0)
			e->hit = 1;
	}
}

void	get_start_end(t_env *e)
{
	if (e->side == 0)
		e->d_ray = (e->map_x - e->ray_pos_x + (1 - e->way_x) / 2)
			/ e->ray_dir_x;
	else
		e->d_ray = (e->map_y - e->ray_pos_y + (1 - e->way_y) / 2)
			/ e->ray_dir_y;
	e->height_line = (int)(MAP_H / e->d_ray);
	e->start = (e->height_line * -1) / 2 + MAP_H / e->updown;
	if (e->start < 0)
		e->start = 0;
	e->end = e->height_line / 2 + MAP_H / e->updown;
	if (e->end >= MAP_H)
		e->end = MAP_H - 1;
}
