#include "wolf.h"

int		expose(t_env *e)
{
	ray_cast(e);
	return (0);
}

int		main(void)
{
	t_env	e;
	e.pos_x = 22, e.pos_y = 22;
	e.dir_x = -1, e.dir_y = 0;
	e.plane_x = 0, e.plane_y = 0.66;
	e.time = 0, e.old_time = 0;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, MAP_W, MAP_H, "Wolf3d");
	e.img = mlx_new_image(e.mlx, MAP_W, MAP_H);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.size, &e.endian);
	mlx_expose_hook(e.win, expose, &e);
	mlx_loop(e.mlx);
	return (0);
}
