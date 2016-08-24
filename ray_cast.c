#include "wolf.h"

void	ray_cast(t_env *e)
{
	double	x;
	double	y;

	x = 0;
	while (x < MAP_W)
	{
		y = 0;
		e->cam_x = 2 * x / MAP_W - 1;
		e->ray_pos_x = e->pos_x;
		e->ray_pos_y = e->pos_y;
		e->ray_dir_x = e->dir_x + (e->plane_x * e->cam_x);
		e->ray_dir_y = e->dir_y + (e->plane_y * e->cam_x);
		e->map_x = (int)e->ray_pos_x;
		e->map_y = (int)e->ray_pos_y;
		e->x_a = sqrt(1 + (e->ray_dir_y * e->ray_dir_y) / (e->ray_dir_x * e->ray_dir_x));
		e->y_a = sqrt(1 + (e->ray_dir_x * e->ray_dir_x) / (e->ray_dir_y * e->ray_dir_y));
		e->hit = 0;
		get_way_and_dist(e);
		dda_algo(e);
		get_start_end(e);
		while (y < MAP_H)
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
