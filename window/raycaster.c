
#include "../cube.h"



/*
map_ : the square the ray is currently inside (int coordniates)
*/
void	dda(t_dda *dda, char **map)
{
	int	side;
	int	hit;

	side = 0;
	hit = 0;
	while(hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			side = 1;
		}
		if (map[dda->map_x][dda->map_y] == '1')
			hit = 1;
	}
	if (side == 0)
		dda->perp_wall_dist = dda->side_dist_x - dda->delta_dist_x;
	else
		dda->perp_wall_dist = dda->side_dist_y - dda->delta_dist_y;
	// printf("\nray_dir_x: %f, ray_dir_y: %f, cameraperp_wall_dist: %f",dda->ray_dir_x, dda->ray_dir_y, dda->perp_wall_dist);
}

void	calc_line(t_base *base, int nr_ray)
{
	int	line_height;
	int	y_start;
	int	y_end;
	double x_start; //printing image until width = 64
	double x_end;
	double image_width;

	image_width = (double) WIN_W / (double) base->map_depth;
	line_height = (int)(WIN_H / base->dda->perp_wall_dist);
	y_start = -line_height / 2 + WIN_H / 2;
	if (y_start < 0)
		y_start = 0;
	y_end = line_height / 2 + WIN_H / 2;
	if (y_end >= WIN_H)
		y_end = WIN_H - 1;
	x_end = (double) nr_ray * image_width;
	x_start = x_end + image_width;
	// printf("\nWIN_H: %i, line_heigth: %i, image width: %f, map_depth: %i", WIN_H, line_height, image_width, base->map_depth);
	while (x_start > x_end)
	{
		// printf("\ndraw_start: %i, draw_end: %i", draw_start, draw_end);
		// printf("\ni: %i, x: %i", i, x);
		y_start = -line_height / 2 + WIN_H / 2;
		if (y_start < 0)
			y_start = 0;
		//draw_line(draw_start, draw_end, base, i);
		while (y_start < y_end)
		{
			//printf("draw_start: %i, draw_end: %i", draw_start, draw_end);
			mlx_pixel_put(base->libx.mlx, base->libx.win, x_start, y_start, get_rgb("255,255,255"));
			y_start++;
		}
		x_start--;
	}
}

/*
side_dist_ : distance of ray from first pos to next x and y-side
step_ : direction of next step, always 1 or -1 (if negative or positive)
*/
void	init_step_sidedist(t_dda *dda)
{
	if (dda->ray_dir_x > 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (dda->pos_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - dda->pos_x) * dda->delta_dist_x;
	}
	if (dda->ray_dir_y > 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (dda->pos_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - dda->pos_y) * dda->delta_dist_y;
	}
}

/*
camera_x : is the precentile on the x_achsis of the plane
ray_dir_ : x and y direction of ray
delta_dist_ : distance to next x and y-side
*/
void	init_rays(t_dda *dda, int x, int width)
{
		if (get_dda()->dir == 'N' || get_dda()->dir == 'S')
			dda->camera_x = 1.0 - (double)(2 * x) / width;
		else if (get_dda()->dir == 'E' || get_dda()->dir == 'W')
			dda->camera_x = (double)(2 * x) / width - 1;
		dda->ray_dir_x = dda->dir_x + dda->plane_x * dda->camera_x;
		dda->ray_dir_y = dda->dir_y + dda->plane_y * dda->camera_x;
		dda->delta_dist_x = sqrt(1 + (dda->ray_dir_y * dda->ray_dir_y) / (dda->ray_dir_x * dda->ray_dir_x));
		dda->delta_dist_y = sqrt(1 + (dda->ray_dir_x * dda->ray_dir_x) / (dda->ray_dir_y * dda->ray_dir_y));
		dda->hit = 0;
		dda->map_x = (int) dda->pos_x;
		dda->map_y = (int) dda->pos_y;
}


void	start_dda(void)
{
	t_base	*base;
	int		x;

	base = getb();
	// base->map_depth = 6;
	//printf("\npos: %f %f", base->dda->pos_x, base->dda->pos_y);
	paint_background(base);
	x = 0;
	base->map_depth = 100;
	while(x < base->map_depth)
	{
		init_rays(base->dda, x, base->map_depth);
		init_step_sidedist(base->dda);
		dda(base->dda, base->map);
		calc_line(base, x);
		x++;
	}
}
