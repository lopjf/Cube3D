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
		//mlx_pixel_put(base->libx.mlx, base->libx.win, x_start, y_start, get_rgb("255,255,255"));
		// get_color_tex('N', 0, 0);
		y_start++;
	}
	while (y_start < WIN_H)
	{
		mlx_pixel_put(base->libx.mlx, base->libx.win, x_start, y_start, get_rgb(getb()->data.f_path));
		y_start++;
	}
}

// returns the wall direction that was hit (N, E, S, W)
void	get_wall_side(t_dda *dda)
{
	if (dda->wall == 0)
	{
		if (dda->step_x > 0 && dda->map_x > dda->pos_x)
			dda->wall_tex = 'W';
		else if (dda->step_x < 0 && dda->map_x < dda->pos_x)
			dda->wall_tex = 'E';
	}
	else
	{
		if (dda->step_y > 0 && dda->map_y > dda->pos_y)
			dda->wall_tex = 'S';
		if (dda->step_y < 0 && dda->map_y < dda->pos_y)
			dda->wall_tex = 'N';
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
	if ((dda->wall == 0 && dda->ray_dir_x > 0) || (dda->wall == 1 && dda->ray_dir_y < 0))
		tex_x = TEX_W - tex_x - 1;
	return (tex_x);
}

void	draw_wall(t_base *base, int x)
{
	double	step;
	double	line_height;
	double	tex_pos;
	double	y_start;
	double	y_end;
	int		tex_y;
	int		tex_x;

	line_height = (int)(WIN_H / base->dda->perp_wall_dist);
	step = 1.0 * TEX_H / line_height;
	y_start = -line_height / 2 + WIN_H / 2;
	if (y_start < 0)
		y_start = 0;
	y_end = line_height / 2 + WIN_H / 2;
	if (y_end >= WIN_H)
		y_end = WIN_H - 1;
	tex_pos = (y_start - WIN_H / 2 + line_height / 2) * step;
	tex_x = calc_wall_pos(base->dda);
	while (y_start < y_end)
	{
		tex_y = (int) tex_pos & ( TEX_H - 1 );
		tex_pos += step;
		mlx_pixel_put(base->libx.mlx, base->libx.win, x, y_start, get_rgb(get_color_tex(base->dda->wall_tex, tex_x, tex_y)));
		y_start++;
	}
}
