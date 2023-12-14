#include "../cube.h"

void	draw_line(double y_end, double x_start, double line_height, t_base *base)
{
	double y_start;
	double i;

	i = 0;
	y_start = -line_height / 2 + WIN_H / 2;
	if (y_start < 0)
		y_start = 0;
	while (i <	y_start)
	{
		mlx_pixel_put(base->libx.mlx, base->libx.win, x_start, i, get_rgb(getb()->data.c_path));
		i++;
	}
	while (y_start < y_end)
	{
		mlx_pixel_put(base->libx.mlx, base->libx.win, x_start, y_start, get_rgb("255,255,255"));
		y_start++;
	}
	while (y_start < WIN_H)
	{
		mlx_pixel_put(base->libx.mlx, base->libx.win, x_start, y_start, get_rgb(getb()->data.f_path));
		y_start++;
	}
}

// returns the wall direction that was hit (N, E, S, W)
char	get_wall_side(t_dda *dda)
{
	char	wall_tex;

	wall_tex = '0';
	if (dda->wall == 0)
	{
		if (dda->step_x > 0 && dda->map_x > dda->pos_x)
			wall_tex = 'W';
		else if (dda->step_x < 0 && dda->map_x < dda->pos_x)
			wall_tex = 'E';
	}
	else
	{
		if (dda->step_y > 0 && dda->map_y > dda->pos_y)
			wall_tex = 'S';
		if (dda->step_y < 0 && dda->map_y < dda->pos_y)
			wall_tex = 'N';
	}
	return (wall_tex);
}
