#include "wolf.h"

void	get_pxl_col(t_env *e, t_col *col, int i)
{
	int d;

	d = i * 256 - MAP_H * 128 + e->height_line * 128;
	e->tex_y = ((d * TEX_HEIGHT) / e->height_line) / 256;
	col->b = e->tex_tab[e->tex_id].data[(e->tex_y
			* e->tex_tab[e->tex_id].size
			+ e->tex_tab[e->tex_id].bpp / 8
			* e->tex_x)];
	col->g = e->tex_tab[e->tex_id].data[(e->tex_y
			* e->tex_tab[e->tex_id].size
			+ e->tex_tab[e->tex_id].bpp / 8
			* e->tex_x) + 1];
	col->r = e->tex_tab[e->tex_id].data[(e->tex_y
			* e->tex_tab[e->tex_id].size
			+ e->tex_tab[e->tex_id].bpp / 8
			* e->tex_x) + 2];
}
