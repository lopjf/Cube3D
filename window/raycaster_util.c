
#include "../cube.h"

void	ft_swap_nr(int *a, int *b)
{
	int	tmp;

	printf("\ninside swap nr");
	tmp = *a;
	*a = *b;
	*b = tmp;

}

void	paint_black(t_base *base)
{
	int	x;
	int	y;

	y = 0;
	while (y <= WIN_H)
	{
		x = 0;
		while (x <= WIN_W)
		{
			mlx_pixel_put(base->libx.mlx, base->libx.win, x, y, get_rgb("0,0,0"));
			x++;
		}
		y++;
	}
}


// not working
void	draw_line(int draw_start, int draw_end, t_base *base, int x)
{
	int	y;

	printf("\ndrawstart: %i, draw_end: %i", draw_start, draw_end);
	//if (draw_start > draw_end)
	//	ft_swap_nr(&draw_start, &draw_end);
	y = 0;
	while (y < draw_start)
	{
		mlx_pixel_put(base->libx.mlx, base->libx.win, x, y, get_rgb("0,0,0"));
		y++;
	}
	while (y < draw_end)
	{
		mlx_pixel_put(base->libx.mlx, base->libx.win, x, y, get_rgb("120,93,21"));
		y++;
	}
	while (y < WIN_H)
	{
		mlx_pixel_put(base->libx.mlx, base->libx.win, x, y, get_rgb("120,120,120"));
		y++;
	}
}
