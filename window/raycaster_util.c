/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:21:03 by loris             #+#    #+#             */
/*   Updated: 2023/12/15 19:22:40 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	draw_ceil_floor(double y_end, double x, double line_h, t_base *base)
{
	double	y_start;
	double	i;

	i = 0;
	y_start = -line_h / 2 + WIN_H / 2;
	if (y_start < 0)
		y_start = 0;
	while (i < y_start)
	{
		mlx_pixel_put(base->libx.mlx, base->libx.win, x, i, \
		get_rgb(getb()->data.c_path));
		i++;
	}
	while (y_start < y_end)
		y_start++;
	while (y_start < WIN_H)
	{
		mlx_pixel_put(base->libx.mlx, base->libx.win, x, y_start, \
		get_rgb(getb()->data.f_path));
		y_start++;
	}
}

// returns the wall direction that was hit (N, E, S, W)
void	get_wall_side(t_dda *dda)
{
	if (dda->wall == 0)
	{
		if (dda->step_x > 0 && dda->map_x > dda->pos_x)
			dda->wall_tex = 'S';
		else if (dda->step_x < 0 && dda->map_x < dda->pos_x)
			dda->wall_tex = 'N';
	}
	else
	{
		if (dda->step_y > 0 && dda->map_y > dda->pos_y)
			dda->wall_tex = 'E';
		if (dda->step_y < 0 && dda->map_y < dda->pos_y)
			dda->wall_tex = 'W';
	}
}

//wall_x: exact value where on tile wall was hit
int	calc_wall_pos(t_dda *dda)
{
	double	wall_x;
	int		tex_x;

	if (dda->wall == 0)
		wall_x = dda->pos_y + dda->perp_wall_dist * dda->ray_dir_y;
	else
		wall_x = dda->pos_x + dda->perp_wall_dist * dda->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double) TEX_W);
	if ((dda->wall == 0 && dda->ray_dir_x > 0) || \
	(dda->wall == 1 && dda->ray_dir_y < 0))
		tex_x = TEX_W - tex_x - 1;
	return (tex_x);
}

void	draw_wall(t_base *base, int x, double y_start, double y_end)
{
	double	step;
	double	line_height;
	double	tex_pos;
	int		tex_y;
	int		tex_x;

	line_height = (int)(WIN_H / base->dda->perp_wall_dist);
	step = 1.0 * TEX_H / line_height;
	tex_pos = (y_start - WIN_H / 2 + line_height / 2) * step;
	tex_x = calc_wall_pos(base->dda);
	while (y_start < y_end)
	{
		tex_y = (int) tex_pos & (TEX_H - 1);
		tex_pos += step;
		get_wall_side(base->dda);
		mlx_pixel_put(base->libx.mlx, base->libx.win, x, y_start, \
		get_color_tex(base->dda->wall_tex, tex_x, tex_y));
		y_start++;
	}
}
