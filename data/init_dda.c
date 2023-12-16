/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:18:47 by loris             #+#    #+#             */
/*   Updated: 2023/12/16 19:54:47 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_dda	*get_dda(void)
{
	static t_dda	dda;

	return (&dda);
}

static void	init_dir_plane(int dir_x, int dir_y, int planex, int planey)
{
	t_dda	*dda;

	dda = get_dda();
	dda->dir_x = (double) dir_x;
	dda->dir_y = (double) dir_y;
	dda->planex = (double) planex;
	dda->planey = (double) planey;
	dda->nr_rays = 10;
}

static void	get_dir_plane(void)
{
	if (get_dda()->dir == 'N')
		init_dir_plane(1, 0, 0, 1);
	else if (get_dda()->dir == 'S')
		init_dir_plane(-1, 0, 0, -1);
	else if (get_dda()->dir == 'E')
		init_dir_plane(0, -1, -1, 0);
	else if (get_dda()->dir == 'W')
		init_dir_plane(0, 1, 1, 0);
}

void	init_dda(void)
{
	char	**map;
	int		i;
	int		j;

	map = getb()->map;
	i = 1;
	get_dda()->dir = '0';
	while (map[i])
	{
		j = 1;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
			{
				get_dda()->dir = map[i][j];
				get_dda()->posx = (double) i + 0.5;
				get_dda()->posy = (double) j + 0.5;
				break ;
			}
			j++;
		}
		i++;
	}
	get_dir_plane();
}
