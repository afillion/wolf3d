#include "wolf.h"
#include <stdio.h>
#include <math.h>

int		expose(t_env *e)
{
	ray_cast(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	//123=left, 125=down, 124right, 126up
	printf("key = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
	{
		if (e->world_map[(int)(e->pos_x + e->dir_x * e->move_speed)][(int)(e->pos_y)] == 0) e->pos_x += e->dir_x * e->move_speed;
		if (e->world_map[(int)(e->pos_x)][(int)(e->pos_y + e->dir_y * e->move_speed)] == 0) e->pos_y += e->dir_y * e->move_speed;
	}
	if (keycode == 125)
	{
		e->pos_x -= e->dir_x * e->move_speed;
		e->pos_y -= e->dir_y * e->move_speed;
	}
	if (keycode == 124)
	{
		e->old_dir_x = e->dir_x;
		e->dir_x = e->dir_x * cos(-e->rot_speed) - e->dir_y * sin(-e->rot_speed);
		e->dir_y = e->old_dir_x * sin(-e->rot_speed) + e->dir_y * cos(-e->rot_speed);
		e->old_plane_x = e->plane_x;
		e->plane_x = e->plane_x * cos(-e->rot_speed) - e->plane_y * sin(-e->rot_speed);
		e->plane_y = e->old_plane_x * sin(-e->rot_speed) + e->plane_y * cos(-e->rot_speed);
	}
	if (keycode == 123)
	{
		e->old_dir_x = e->dir_x;
		e->dir_x = e->dir_x * cos(e->rot_speed) - e->dir_y * sin(e->rot_speed);
		e->dir_y = e->old_dir_x * sin(e->rot_speed) + e->dir_y * cos(e->rot_speed);
		e->old_plane_x = e->plane_x;
		e->plane_x = e->plane_x * cos(e->rot_speed) - e->plane_y * sin(e->rot_speed);
		e->plane_y = e->old_plane_x * sin(e->rot_speed) + e->plane_y * cos(e->rot_speed);
	}
	ray_cast(e);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;
	e.pos_x = 22, e.pos_y = 12;
	e.dir_x = -1, e.dir_y = 0;
	e.plane_x = 0, e.plane_y = 0.66;
	e.time = 0, e.old_time = 0;
	e.move_speed = 1;
	e.rot_speed = 0.2;
	e.line = 0;
	e.col = 0;

	if (ac == 2)
	{
		e.filename = av[1];
		parse_map(&e);
	}
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, MAP_W, MAP_H, "Wolf3d");
	e.img = mlx_new_image(e.mlx, MAP_W, MAP_H);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.size, &e.endian);
	mlx_expose_hook(e.win, expose, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
