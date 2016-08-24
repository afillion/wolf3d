#include "wolf.h"

void	init_ray(t_env *e)
{
	e->ray_pos_x = e->pos_x;
	e->ray_pos_y = e->pos_y;
	e->ray_dir_x = e->dir_x + (e->plane_x * e->cam_x);
	e->ray_dir_y = e->dir_y + (e->plane_y * e->cam_x);
	e->map_x = (int)e->ray_pos_x;
	e->map_y = (int)e->ray_pos_y;
	e->x_a = sqrt(1 + (e->ray_dir_y * e->ray_dir_y)
			/ (e->ray_dir_x * e->ray_dir_x));
	e->y_a = sqrt(1 + (e->ray_dir_x * e->ray_dir_x)
			/ (e->ray_dir_y * e->ray_dir_y));
	e->hit = 0;
}

void	init_struct(t_env *e)
{
	e->pos_x = 22;
	e->pos_y = 12;
	e->dir_x = -1;
	e->dir_y = 0;
	e->plane_x = 0;
	e->plane_y = 0.66;
	e->time = 0;
	e->old_time = 0;
	e->move_speed = 0.15;
	e->rot_speed = 0.07;
	e->line = 0;
	e->col = 0;
}
