
#include "cube.h"

t_dda	*get_dda(void)
{
	static t_dda dda;

	return (&dda);
}

void	init_dir_plane(int dirX, int dirY, int planeX, int planeY)
{
	t_dda	*dda;

	dda = get_dda();
	dda->dirX = dirX;
	dda->dirY = dirY;
	dda->planeX = planeX;
	dda->planeY = planeY;
}

void get_dir_plane(char dir)
{

	if (dir == 'N')
		init_dir_plane(0, 1, 1, 0);
	else if (dir == 'S')
		init_dir_plane(0, -1, -1, 0);
	else if (dir == 'E')
		init_dir_plane(1, 0, 0, 1);
	else if (dir == 'N')
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
	j = 1;
	dir = '0';
	while(map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
			{
				dir = map[i][j];
				get_dda()->posX = i;
				get_dda()->posY = j;
				break;
			}
			j++;
		}
		i++;
	}
	get_dir_plane(dir);
}
