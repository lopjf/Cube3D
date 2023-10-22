#include "cube.h"

void update_pos(int keycode)
{
	if (keycode == KEY_W)
	{
		get_dda()->pos_x += get_dda()->dir_x;
		get_dda()->pos_y += get_dda()->dir_y;
	}
	else if (keycode == KEY_S)
	{
		get_dda()->pos_x -= get_dda()->dir_x;
		get_dda()->pos_y -= get_dda()->dir_y;
	}
	else if (keycode == KEY_D)
	{
		get_dda()->pos_x += get_dda()->plane_x;
		get_dda()->pos_y += get_dda()->plane_y;
	}
	else if (keycode == KEY_A)
	{
		get_dda()->pos_x -= get_dda()->plane_x;
		get_dda()->pos_y -= get_dda()->plane_y;
	}
}

void update_dir(int keycode)
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

void update_plane(int keycode)
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
