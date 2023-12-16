/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:20:17 by loris             #+#    #+#             */
/*   Updated: 2023/12/16 19:56:49 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	check_next_pos(int keycode, int x, int y)
{
	t_dda	*d;

	d = get_dda();
	if (keycode == KEY_W)
		xy(&x, &y, (d->posx - d->dir_x), (d->posy - d->dir_y));
	else if (keycode == KEY_S)
		xy(&x, &y, (d->posx + d->dir_x), (d->posy + d->dir_y));
	else if (keycode == KEY_D)
	{
		if (d->dir == 'N' || d->dir == 'S')
			xy(&x, &y, (d->posx + d->planex), (d->posy + d->planey));
		else if (d->dir == 'E' || d->dir == 'W')
			xy(&x, &y, (d->posx - d->planex), (d->posy - d->planey));
	}
	else if (keycode == KEY_A)
	{
		if (d->dir == 'N' || d->dir == 'S')
			xy(&x, &y, (d->posx - d->planex), (d->posy - d->planey));
		else if (d->dir == 'E' || d->dir == 'W')
			xy(&x, &y, (d->posx + d->planex), (d->posy + d->planey));
	}
	if (getb()->map[x][y] == '1' || getb()->map[x][y] \
	== ' ' || getb()->map[x][y] == '\0')
		return (0);
	return (1);
}

void	update_pos(int keycode)
{
	t_dda	*d;

	d = get_dda();
	if (check_next_pos(keycode, 0, 0) == 0)
		return ;
	if (keycode == KEY_W)
		a(&d->posx, &d->posy, (d->posx - d->dir_x), (d->posy - d->dir_y));
	else if (keycode == KEY_S)
		a(&d->posx, &d->posy, (d->posx + d->dir_x), (d->posy + d->dir_y));
	else if (keycode == KEY_D)
	{
		if (d->dir == 'N' || d->dir == 'S')
			a(&d->posx, &d->posy, (d->posx + d->planex), (d->posy + d->planey));
		else if (d->dir == 'E' || d->dir == 'W')
			a(&d->posx, &d->posy, (d->posx - d->planex), (d->posy - d->planey));
	}
	else if (keycode == KEY_A)
	{
		if (d->dir == 'N' || d->dir == 'S')
			a(&d->posx, &d->posy, (d->posx - d->planex), (d->posy - d->planey));
		else if (d->dir == 'E' || d->dir == 'W')
			a(&d->posx, &d->posy, (d->posx + d->planex), (d->posy + d->planey));
	}
}

void	update_dir(int keycode)
{
	double	old_dir_x;

	if (keycode == KEY_RA)
	{
		old_dir_x = get_dda()->dir_x;
		get_dda()->dir_x = get_dda()->dir_x * cos(-ROT_SPEED) - \
		get_dda()->dir_y * sin(-ROT_SPEED);
		get_dda()->dir_y = old_dir_x * sin(-ROT_SPEED) + \
		get_dda()->dir_y * cos(-ROT_SPEED);
	}
	else if (keycode == KEY_LA)
	{
		old_dir_x = get_dda()->dir_x;
		get_dda()->dir_x = get_dda()->dir_x * cos(ROT_SPEED) - \
		get_dda()->dir_y * sin(ROT_SPEED);
		get_dda()->dir_y = old_dir_x * sin(ROT_SPEED) + \
		get_dda()->dir_y * cos(ROT_SPEED);
	}
}

void	update_plane(int keycode)
{
	double	old_plane_x;

	if (keycode == KEY_RA)
	{
		old_plane_x = get_dda()->planex;
		get_dda()->planex = get_dda()->planex * cos(-ROT_SPEED) - \
		get_dda()->planey * sin(-ROT_SPEED);
		get_dda()->planey = old_plane_x * sin(-ROT_SPEED) + \
		get_dda()->planey * cos(-ROT_SPEED);
	}
	else if (keycode == KEY_LA)
	{
		old_plane_x = get_dda()->planex;
		get_dda()->planex = get_dda()->planex * cos(ROT_SPEED) - \
		get_dda()->planey * sin(ROT_SPEED);
		get_dda()->planey = old_plane_x * sin(ROT_SPEED) + \
		get_dda()->planey * cos(ROT_SPEED);
	}
}
