#include "cube.h"

static int	check_next_pos(int keycode, int x, int y)
{
	if (keycode == KEY_W)
	{
		x = (int)(get_dda()->pos_x - get_dda()->dir_x);
		y = (int)(get_dda()->pos_y - get_dda()->dir_y);
	}
	else if (keycode == KEY_S)
	{
		x = (int)(get_dda()->pos_x + get_dda()->dir_x);
		y = (int)(get_dda()->pos_y + get_dda()->dir_y);
	}
	else if (keycode == KEY_D)
	{
		if (get_dda()->dir == 'N' || get_dda()->dir == 'S')
		{
			x = (int)(get_dda()->pos_x + get_dda()->plane_x);
			y = (int)(get_dda()->pos_y + get_dda()->plane_y);
		}
		else if (get_dda()->dir == 'E' || get_dda()->dir == 'W')
		{
			x = (int)(get_dda()->pos_x - get_dda()->plane_x);
			y = (int)(get_dda()->pos_y - get_dda()->plane_y);
		}
	}
	else if (keycode == KEY_A)
	{
		if (get_dda()->dir == 'N' || get_dda()->dir == 'S')
		{
			x = (int)(get_dda()->pos_x - get_dda()->plane_x);
			y = (int)(get_dda()->pos_y - get_dda()->plane_y);
		}
		else if (get_dda()->dir == 'E' || get_dda()->dir == 'W')
		{
			x = (int)(get_dda()->pos_x + get_dda()->plane_x);
			y = (int)(get_dda()->pos_y + get_dda()->plane_y);
		}
	}
	if (getb()->map[x][y] == '1' || getb()->map[x][y] == ' ' || getb()->map[x][y] == '\0')
		return (0);
	return (1);
}

void	update_pos(int keycode)
{
	if (check_next_pos(keycode, 0, 0) == 0)
		return;
	if (keycode == KEY_W)
	{
		get_dda()->pos_x -= get_dda()->dir_x;
		get_dda()->pos_y -= get_dda()->dir_y;
	}
	else if (keycode == KEY_S)
	{
		get_dda()->pos_x += get_dda()->dir_x;
		get_dda()->pos_y += get_dda()->dir_y;
	}
	else if (keycode == KEY_D)
	{
		if (get_dda()->dir == 'N' || get_dda()->dir == 'S')
		{
			get_dda()->pos_x += get_dda()->plane_x;
			get_dda()->pos_y += get_dda()->plane_y;
		}
		else if (get_dda()->dir == 'E' || get_dda()->dir == 'W')
		{
			get_dda()->pos_x -= get_dda()->plane_x;
			get_dda()->pos_y -= get_dda()->plane_y;
		}
	}
	else if (keycode == KEY_A)
	{
		if (get_dda()->dir == 'N' || get_dda()->dir == 'S')
		{
			get_dda()->pos_x -= get_dda()->plane_x;
			get_dda()->pos_y -= get_dda()->plane_y;
		}
		else if (get_dda()->dir == 'E' || get_dda()->dir == 'W')
		{
			get_dda()->pos_x += get_dda()->plane_x;
			get_dda()->pos_y += get_dda()->plane_y;
		}
	}
}

void	update_dir(int keycode)
{
	double	old_dir_x;

	if (keycode == KEY_RA)
	{
		old_dir_x = get_dda()->dir_x;
		get_dda()->dir_x = get_dda()->dir_x * cos(-ROT_SPEED) - get_dda()->dir_y * sin(-ROT_SPEED);
		get_dda()->dir_y = old_dir_x * sin(-ROT_SPEED) + get_dda()->dir_y * cos(-ROT_SPEED);
	}
	else if (keycode == KEY_LA)
	{
		old_dir_x = get_dda()->dir_x;
		get_dda()->dir_x = get_dda()->dir_x * cos(ROT_SPEED) - get_dda()->dir_y * sin(ROT_SPEED);
		get_dda()->dir_y = old_dir_x * sin(ROT_SPEED) + get_dda()->dir_y * cos(ROT_SPEED);
	}
}

void	update_plane(int keycode)
{
	double old_plane_x;

	if (keycode == KEY_RA)
	{
		old_plane_x = get_dda()->plane_x;
		get_dda()->plane_x = get_dda()->plane_x * cos(-ROT_SPEED) - get_dda()->plane_y * sin(-ROT_SPEED);
		get_dda()->plane_y = old_plane_x * sin(-ROT_SPEED) + get_dda()->plane_y * cos(-ROT_SPEED);
	}
	else if (keycode == KEY_LA)
	{
		old_plane_x = get_dda()->plane_x;
		get_dda()->plane_x = get_dda()->plane_x * cos(ROT_SPEED) - get_dda()->plane_y * sin(ROT_SPEED);
		get_dda()->plane_y = old_plane_x * sin(ROT_SPEED) + get_dda()->plane_y * cos(ROT_SPEED);
	}
}
