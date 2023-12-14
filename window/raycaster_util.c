#include "../cube.h"

void	ft_swap_nr(int *a, int *b)
{
	int	tmp;

	printf("\ninside swap nr");
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	paint_background(t_base *base)
{
	// mlx_clear_window(base->libx.mlx, base->libx.win);
	int	x;
	int	y;

	y = 0;
	while (y <= WIN_H / 2)
	{
		x = 0;
		while (x <= WIN_W)
		{
			mlx_pixel_put(base->libx.mlx, base->libx.win,
			x, y, get_rgb(getb()->data.c_path));
			x++;
		}
		y++;
	}
	while (y <= WIN_H)
	{
		x = 0;
		while (x <= WIN_W)
		{
			mlx_pixel_put(base->libx.mlx, base->libx.win,
			x, y, get_rgb(getb()->data.f_path));
			x++;
		}
		y++;
	}
}


void	draw_line(double y_end, double x_start, double line_height, t_base *base)
{
	double y_start;

	y_start = -line_height / 2 + WIN_H / 2;
	if (y_start < 0)
		y_start = 0;
	while (y_start < y_end)
	{
		mlx_pixel_put(base->libx.mlx, base->libx.win, x_start, y_start, get_rgb("255,255,255"));
		y_start++;
	}
}
