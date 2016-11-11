#include "wolf.h"

void	texel(t_env *e)
{
	e->tex_id = e->world_map[e->map_x][e->map_y] - 1;
	if (e->side == 0)
		e->wall_x = e->ray_pos_y + e->d_ray * e->ray_dir_y;
	else
		e->wall_x = e->ray_pos_x + e->d_ray * e->ray_dir_x;
	e->wall_x -= floor((e->wall_x));
	//e->wall_x *= TEX_HEIGHT;
	//e->wall_x = (int)e->wall_x;
	e->tex_x = (int)(e->wall_x * (double)TEX_WIDTH);
	if (e->tex_x >= 64)
		e->tex_x = e->tex_x % 64;
	if (e->side == 0 && e->ray_dir_x > 0)
		e->tex_x = TEX_WIDTH - e->tex_x - 1;
	if (e->side == 1 && e->ray_dir_y < 0)
		e->tex_x = TEX_WIDTH - e->tex_x - 1;
}

int		loader(t_env *e, t_tex *image, char *file)
{
	int		w;
	int		h;

	w = TEX_WIDTH;
	h = TEX_HEIGHT;
	if (!(image->img = mlx_xpm_file_to_image(e->mlx, file, &w, &h)))
		return (-1);
	image->data = mlx_get_data_addr(image->img, &image->bpp, &image->size, &image->endian);
	return (0);
}

int		tex_init(t_env *e)
{
	loader(e, &e->tex_tab[0], "./Texture/barrel.xpm");
	loader(e, &e->tex_tab[1], "./Texture/bluestone.xpm");
	loader(e, &e->tex_tab[2], "./Texture/colorstone.xpm");
	loader(e, &e->tex_tab[3], "./Texture/eagle.xpm");
	loader(e, &e->tex_tab[4], "./Texture/greystone.xpm");
	if (!e->tex_tab[0].img || !e->tex_tab[1].img || !e->tex_tab[2].img || !e->tex_tab[3].img || !e->tex_tab[4].img)
		return (-1);
	return (0);
}
