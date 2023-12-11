
#include "cube.h"

t_dda	*get_dda(void)
{
	static t_dda	dda;

	return (&dda);
}

void	init_dir_plane(int dir_x, int dir_y, int plane_x, int plane_y)
{
	t_dda	*dda;

	dda = get_dda();
	dda->dir_x = (double) dir_x;
	dda->dir_y = (double) dir_y;
	dda->plane_x = (double) plane_x;
	dda->plane_y = (double) plane_y;
	dda->nr_rays = 10;
}

void	get_dir_plane()
{
	if (get_dda()->dir == 'N')
		init_dir_plane(1, 0, 0, 1);
	else if (get_dda()->dir == 'S')
		init_dir_plane(-1, 0, 0, -1);
	else if (get_dda()->dir == 'E')
		init_dir_plane(0, -1, -1, 0);
	else if (get_dda()->dir == 'W')
		init_dir_plane(0, 1, 1, 0);

		// When starting the game with N or S, the map is reversed, and the right and left arrow as well.
		// We can never look west on the maps. Only east works.
		// Moves are working fine for all directions.

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
			//if (write(1, "\n", 1)== -1) {}
			//if (write(1, &map[i][j], 1)== -1) {}
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
			{
				get_dda()->dir = map[i][j];
				get_dda()->pos_x = (double) i + 0.5;
				get_dda()->pos_y = (double) j + 0.5;
				break ;
			}
			j++;
		}
		i++;
	}
	get_dir_plane();
}
