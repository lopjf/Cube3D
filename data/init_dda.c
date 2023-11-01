
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

void	get_dir_plane(char dir)
{
	if (dir == 'N')
		init_dir_plane(0, 1, 1, 0);
	else if (dir == 'S')
		init_dir_plane(0, -1, -1, 0);
	else if (dir == 'E')
		init_dir_plane(1, 0, 0, 1);
	else if (dir == 'W')
		init_dir_plane(-1, 0, 0, -1);
}

void	init_dda(void)
{
	char	**map;
	int		i;
	int		j;
	char	dir;

	map = getb()->map;
	i = 1;
	dir = '0';

	while (map[i])
	{
		j = 1;
		while (map[i][j] != '\0')
		{
			//if (write(1, "\n", 1)== -1) {}
			//if (write(1, &map[i][j], 1)== -1) {}
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
			{
				dir = map[i][j];
				get_dda()->pos_x = (double) i;
				get_dda()->pos_y = (double) j;
				break ;
			}
			j++;
		}
		i++;
	}
	get_dir_plane(dir);
}
