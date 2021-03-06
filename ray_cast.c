#include "wolf.h"

void	ray_cast(t_env *e)
{
	double		y;
	double		x;
	int			i;
	t_col		col;

	x = 0;
	while (x < MAP_W)
	{
		y = 0;
		e->cam_x = 2 * x / MAP_W - 1;
		init_ray(e);
		get_way_and_dist(e);
		dda_algo(e);
		get_start_end(e);
//		texel(e);
		i = e->start;
		while (y < MAP_H)
		{
			color(e, y);
			put_pixel_to_img(e, &col, x, y);
			y++;
		}
//		while (i < e->end)
//		{
//			//e->tex_y = (i * 2 - MAP_H + e->height_line) * (TEX_HEIGHT / 2) / e->height_line;
//			get_pxl_col(e, &col, i);
//			put_pixel_to_img(e, &col, x, i);
//			i++;
//		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
