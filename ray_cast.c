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
		init_ray(e);
		get_way_and_dist(e);
		dda_algo(e);
		get_start_end(e);
		while (y < MAP_H)
		{
			color(e, y);
			put_pixel_to_img(e, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
