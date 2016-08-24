#include "wolf.h"

void	right_rotate(t_env *e)
{
	e->old_dir_x = e->dir_x;
	e->dir_x = e->dir_x * cos(-e->rot_speed) - e->dir_y * sin(-e->rot_speed);
	e->dir_y = e->old_dir_x * sin(-e->rot_speed)
		+ e->dir_y * cos(-e->rot_speed);
	e->old_plane_x = e->plane_x;
	e->plane_x = e->plane_x * cos(-e->rot_speed)
		- e->plane_y * sin(-e->rot_speed);
	e->plane_y = e->old_plane_x * sin(-e->rot_speed)
		+ e->plane_y * cos(-e->rot_speed);
}

void	left_rotate(t_env *e)
{
	e->old_dir_x = e->dir_x;
	e->dir_x = e->dir_x * cos(e->rot_speed) - e->dir_y * sin(e->rot_speed);
	e->dir_y = e->old_dir_x * sin(e->rot_speed) + e->dir_y * cos(e->rot_speed);
	e->old_plane_x = e->plane_x;
	e->plane_x = e->plane_x * cos(e->rot_speed)
		- e->plane_y * sin(e->rot_speed);
	e->plane_y = e->old_plane_x * sin(e->rot_speed)
		+ e->plane_y * cos(e->rot_speed);
}

void	updown_view(t_env *e)
{
	if (e->up == 1)
		e->updown = 1.5;
	if (e->down == 1)
		e->updown = 3;
}
