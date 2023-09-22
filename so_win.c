#include "cube.h"

int	check_if_can_move(t_base *base, int keycode, int i, int x_lenght)
{
	int	c;
	int	k;

	c = 0;
	k = 0;
	while (base->map[k])
		if (base->map[k++] == 'C')
			c = 1;
	if (keycode == KEY_W && base->map[i - x_lenght] == '1')
		return (0);
	else if (keycode == KEY_D && base->map[i + 1] == '1')
		return (0);
	else if (keycode == KEY_S && base->map[i + x_lenght] == '1')
		return (0);
	else if (keycode == KEY_A && base->map[i - 1] == '1')
		return (0);
	if (keycode == KEY_W && base->map[i - x_lenght] == 'E' && c == 1)
		return (0);
	else if (keycode == KEY_D && base->map[i + 1] == 'E' && c == 1)
		return (0);
	else if (keycode == KEY_S && base->map[i + x_lenght] == 'E' && c == 1)
		return (0);
	else if (keycode == KEY_A && base->map[i - 1] == 'E' && c == 1)
		return (0);
	return (1);
}

void	replace_pics_and_map(int keycode, t_base *base, int i, int x_lenght)
{
	if (keycode == KEY_W)
	{
		if (base->map[i - x_lenght] == 'E')
			close_victory(base);
		base->map[i - x_lenght] = 'P';
	}
	else if (keycode == KEY_D)
	{
		if (base->map[i + 1] == 'E')
			close_victory(base);
		base->map[i + 1] = 'P';
	}
	else if (keycode == KEY_S)
	{
		if (base->map[i + x_lenght] == 'E')
			close_victory(base);
		base->map[i + x_lenght] = 'P';
	}
	else if (keycode == KEY_A)
	{
		if (base->map[i - 1] == 'E')
			close_victory(base);
		base->map[i - 1] = 'P';
	}
	base->map[i] = '0';
}

int	move(int keycode, t_base *base)
{
	int	x_lenght;
	int	i;

	x_lenght = 0;
	while (base->map[x_lenght] != '\n' && base->map[x_lenght])
		x_lenght++;
	x_lenght++;
	i = 0;
	while (base->map[i] != 'P')
		i++;
	if (check_if_can_move(base, keycode, i, x_lenght) == 1)
	{
		replace_pics_and_map(keycode, base, i, x_lenght);
		return (1);
	}
	return (0);
}

int	display_game(t_base *b, int i, int x, int y)
{
	while (b->map[i])
	{
		if (b->map[i] == '1')
			mlx_put_image_to_window(b->mlx, b->win, b->img.wall, 64 * x, y);
		else if (b->map[i] == '0')
			mlx_put_image_to_window(b->mlx, b->win, b->img.empty, 64 * x, y);
		else if (b->map[i] == 'E')
			mlx_put_image_to_window(b->mlx, b->win, b->img.exit, 64 * x, y);
		else if (b->map[i] == 'P')
			mlx_put_image_to_window(b->mlx, b->win, b->img.player, 64 * x, y);
		else if (b->map[i] == 'C')
			mlx_put_image_to_window(b->mlx, \
			b->win, b->img.collectible, 64 * x, y);
		i++;
		x++;
		if (b->map[i] == '\n')
		{
			x = 0;
			y = y + 64;
			i++;
		}
	}
	return (0);
}
