#include "wolf.h"
#include <stdio.h>
#include <math.h>

int		expose(t_env *e)
{
	ray_cast(e);
	key_hook(e);
	return (0);
}

int		key_hook(t_env *e)
{
	if (e->forward == 1)
	{
		if (e->world_map[(int)(e->pos_x + e->dir_x * e->move_speed)][(int)(e->pos_y)] == 0)
			e->pos_x += e->dir_x * e->move_speed;
		if (e->world_map[(int)(e->pos_x)][(int)(e->pos_y + e->dir_y * e->move_speed)] == 0)
			e->pos_y += e->dir_y * e->move_speed;
	}
	if (e->backward == 1)
	{
		if (e->world_map[(int)(e->pos_x - e->dir_x * e->move_speed)][(int)e->pos_y] == 0)
			e->pos_x -= e->dir_x * e->move_speed;
		if (e->world_map[(int)e->pos_x][(int)(e->pos_y - e->dir_y * e->move_speed)] == 0)
			e->pos_y -= e->dir_y * e->move_speed;
	}
	if (e->left == 1)
	{
		if (e->world_map[(int)(e->pos_x - e->dir_x * e->move_speed)][(int)(e->pos_y)] == 0)
			e->pos_x -= e->dir_x * e->move_speed;
		if (e->world_map[(int)(e->pos_x)][(int)(e->pos_y + e->dir_y * e->move_speed)] == 0)
			e->pos_y += e->dir_y * e->move_speed;
	}
	if (e->right == 1)
	{
		if (e->world_map[(int)(e->pos_x + e->dir_x * e->move_speed)][(int)(e->pos_y)] == 0)
			e->pos_x += e->dir_x * e->move_speed;
		if (e->world_map[(int)(e->pos_x)][(int)(e->pos_y - e->dir_y * e->move_speed)] == 0)
			e->pos_y -= e->dir_y * e->move_speed;
	}
	if (e->rrotate == 1)
	{
		e->old_dir_x = e->dir_x;
		e->dir_x = e->dir_x * cos(-e->rot_speed) - e->dir_y * sin(-e->rot_speed);
		e->dir_y = e->old_dir_x * sin(-e->rot_speed) + e->dir_y * cos(-e->rot_speed);
		e->old_plane_x = e->plane_x;
		e->plane_x = e->plane_x * cos(-e->rot_speed) - e->plane_y * sin(-e->rot_speed);
		e->plane_y = e->old_plane_x * sin(-e->rot_speed) + e->plane_y * cos(-e->rot_speed);
	}
	if (e->lrotate == 1)
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
	e.move_speed = 0.15;
	e.rot_speed = 0.07;
	e.line = 0;
	e.col = 0;

	if (ac == 2)
	{
		e.filename = av[1];
		parse_map(&e);
	}
	init_key(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, MAP_W, MAP_H, "Wolf3d");
	e.img = mlx_new_image(e.mlx, MAP_W, MAP_H);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.size, &e.endian);
	mlx_loop_hook(e.mlx, expose, &e);
//	mlx_expose_hook(e.win, expose, &e);
	mlx_hook(e.win, 2, (1L << 0), &key_press, &e);
	mlx_hook(e.win, 3, (1L << 1), &key_release, &e);
	mlx_loop(e.mlx);
	return (0);
}
