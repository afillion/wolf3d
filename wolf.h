#ifndef WOLF_H
# define WOLF_H
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# define MAP_W 900
# define MAP_H 700

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
	double		cam_x;
	double		cam_y;
	double		ray_pos_x;
	double		ray_pos_y;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		d_x;
	double		d_y;
	double		x_a;
	double		y_a;
	double		d_ray;
	int			way_x;
	int			way_y;
	int			hit;
	int			side;
	int			height_line;
	int			start;
	int			end;
	int			color;
	int			bpp;
	int			size;
	int			endian;
	double		old_dir_x;
	double		old_plane_x;
	double		move_speed;
	double		rot_speed;
	double		h_cam;
	int			line;
	int			col;
	int			**world_map;
	char		*filename;
}				t_env;

void			ray_cast(t_env *e);
void			put_pixel_to_img(t_env *e, double x, double y);
void			parse_map(t_env *e);
int				count_word(const char *s, char c);

#endif
