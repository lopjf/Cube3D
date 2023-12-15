/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:23:44 by loris             #+#    #+#             */
/*   Updated: 2023/12/15 19:23:52 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	display_win(void)
{
	start_dda();
}

int	close_win(void)
{
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.no);
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.so);
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.we);
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.ea);
	mlx_destroy_window(getb()->libx.mlx, getb()->libx.win);
	mlx_destroy_display(getb()->libx.mlx);
	free(getb()->libx.mlx);
	free_data();
	exit(0);
}

int	fetch_key(int keycode)
{
	if (keycode == KEY_ESC)
		close_win();
	else if (keycode == KEY_RA || keycode == KEY_LA)
	{
		update_dir(keycode);
		update_plane(keycode);
		display_win();
	}
	else if (keycode == KEY_W || keycode == KEY_D || \
	keycode == KEY_S || keycode == KEY_A)
	{
		update_pos(keycode);
		display_win();
	}
	return (0);
}
