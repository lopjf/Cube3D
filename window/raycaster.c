
#include "../cube.h"

/*
side_dist_ : distance of ray from first pos to next x and y-side
step_ : direction of next step, always 1 or -1 (if negative or positive)
*/
void	init_step_sidedist(t_dda *dda)
{
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (dda->pos_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - dda->pos_x) * dda->delta_dist_x;
	}
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_x = (dda->pos_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - dda->pos_y) * dda->delta_dist_y;
	}
}

/*
map_ : the square the ray is currently inside (int coordniates)
*/
void	calc_squares(t_base *base)
{


}

/*
camera_x : is the precentile on the x_achsis of the plane
ray_dir_ : x and y direction of ray
delta_dist_ : distance to next x and y-side
nr_rays : amount of rays
*/
void	init_dda()
{
	t_base	*base;
	int		x;
	double	camera_x;

	base = getb();
	x = 0;
	while(x < base->dda->nr_rays)
	{
		camera_x = (double)(2 * x) / base->dda->nr_rays  - 1;
		base->dda->ray_dir_x = base->dda->dir_x + base->dda->plane_x * camera_x;
		base->dda->ray_dir_y = base->dda->dir_y + base->dda->plane_y * camera_x;
		base->dda->delta_dist_x = fabs(1 / base->dda->ray_dir_x); // ex. absolut value of -5 is 5
		base->dda->delta_dist_y = fabs(1 / base->dda->ray_dir_y);
		init_step_sidedist(base->dda);
		x++;
	}
}

