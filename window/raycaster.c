/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:22:44 by loris             #+#    #+#             */
/*   Updated: 2023/12/16 19:54:47 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

/*
map_ : the square the ray is currently inside (int coordniates)
*/
void	dda(t_dda *dda, char **map)
{
	while (dda->hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->wall = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->wall = 1;
		}
		if (map[dda->map_x][dda->map_y] == '1')
			dda->hit = 1;
	}
	if (dda->wall == 0)
		dda->perp_wall_dist = fabs((dda->map_x - dda->posx + \
		(1 - dda->step_x) / 2) / dda->ray_dir_x);
	else
		dda->perp_wall_dist = fabs((dda->map_y - dda->posy + \
		(1 - dda->step_y) / 2) / dda->ray_dir_y);
}

void	calc_line(t_base *base, int x)
{
	double	line_height;
	double	y_end;
	double	y_start;

	line_height = (int)(WIN_H / base->dda->perp_wall_dist);
	y_end = line_height / 2 + WIN_H / 2;
	if (y_end >= WIN_H)
		y_end = WIN_H - 1;
	y_start = -line_height / 2 + WIN_H / 2;
	if (y_start < 0)
		y_start = 0;
	draw_ceil_floor(y_end, x, line_height, base);
	draw_wall(base, x, y_start, y_end);
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
		dda->side_dist_x = (dda->posx - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - dda->posx) * dda->delta_dist_x;
	}
	if (dda->ray_dir_y > 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (dda->posy - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - dda->posy) * dda->delta_dist_y;
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
	dda->ray_dir_x = dda->dir_x + dda->planex * dda->camera_x;
	dda->ray_dir_y = dda->dir_y + dda->planey * dda->camera_x;
	dda->delta_dist_x = sqrt(1 + (dda->ray_dir_y * dda->ray_dir_y) / \
	(dda->ray_dir_x * dda->ray_dir_x));
	dda->delta_dist_y = sqrt(1 + (dda->ray_dir_x * dda->ray_dir_x) / \
	(dda->ray_dir_y * dda->ray_dir_y));
	dda->map_x = (int) dda->posx;
	dda->map_y = (int) dda->posy;
	dda->wall = 0;
	dda->hit = 0;
}

void	start_dda(void)
{
	t_base	*base;
	int		x;

	base = getb();
	x = 0;
	base->map_depth = WIN_W ;
	while (x < base->map_depth)
	{
		init_rays(base->dda, x, base->map_depth);
		init_step_sidedist(base->dda);
		dda(base->dda, base->map);
		calc_line(base, x);
		x++;
	}
}
