#include "wolf.h"
#include "carte.h"

void	ray_cast(t_env *e)
{
	double	x;
	double	y;

	x = 0;
	while (x < MAP_W)
	{
		y = 0;
		e->cam_x = (2 * x) / (MAP_W - 1);
		e->ray_pos_x = e->pos_x;
		e->ray_pos_y = e->pos_y;
		e->ray_dir_x = e->dir_x + (e->plane_x * e->cam_x);
		e->ray_dir_y = e->dir_y + (e->plane_y * e->cam_x);
		e->map_x = (int)e->ray_pos_x;
		e->map_y = (int)e->ray_pos_y;
		e->x_a = sqrt(1 + (e->ray_dir_y * e->ray_dir_y) / (e->ray_dir_x * e->ray_dir_x));
		e->y_a = sqrt(1 + (e->ray_dir_x * e->ray_dir_x) / (e->ray_dir_y * e->ray_dir_y));
		e->hit = 0;
		if (e->ray_dir_x < 0)
		{
			e->way_x = -1;
			e->d_x = (e->ray_pos_x -  e->map_x) * e->x_a;
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
			if (world_map[e->map_x][e->map_y] > 0)
				e->hit = 1;
		}
		if (e->side == 0)
			e->d_ray = (e->map_x - e->ray_pos_x + (1 - e->way_x) / 2) / e->ray_dir_x;
		else
			e->d_ray = (e->map_y - e->ray_pos_y + (1 - e->way_y) / 2) / e->ray_dir_y;
		e->height_line = (int)(MAP_H / e->d_ray);
		e->start = (e->height_line * -1) / 2 + MAP_H / 2;
		if (e->start < 0)
			e->start = 0;
		e->end = e->height_line / 2 + MAP_H / 2;
		if (e->end >= MAP_H)
			e->end = MAP_H - 1;
		while (y < MAP_H)
		{
			e->color = 0xFFFFFF;
			if (world_map[e->map_x][e->map_y] == 1)
				e->color = 0xFF0000;
			if (world_map[e->map_x][e->map_y] == 2)
				e->color = 0x00FF00;
			if (world_map[e->map_x][e->map_y] == 3)
				e->color = 0x0000FF;
			if (world_map[e->map_x][e->map_y] == 4)
				e->color = 0xFFFF00;
			if (!(y >= e->start && y <= e->end))
				e->color = 0x000000;
			if (e->side == 1)
				e->color = e->color / 2;
			put_pixel_to_img(e, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
