#include "cube.h"

void	check_first_last_lines(void)
{
	int	j;
	int	i;

	i = 0;
	j = getb()->map_depth;
	while (getb()->map[0][i] != '\0')
	{
		if (getb()->map[0][i] != '1' && getb()->map[0][i] != ' ')
			free_and_exit("Error: Map is not closed/surrounded by walls.");
		i++;
	}
	i = 0;
	while (getb()->map[j][i] != '\0')
	{
		if (getb()->map[j][i] != '1' && getb()->map[j][i] != ' ')
			free_and_exit("Error: Map is not closed/surrounded by walls.");
		i++;
	}
}

int	is_player_or_zero(int i, int j)
{
	if (getb()->map[i][j] == '0' || getb()->map[i][j] == 'N' || \
getb()->map[i][j] == 'S' || getb()->map[i][j] == 'E' || \
getb()->map[i][j] == 'W')
		return (0);
	return (1);
}

// v for valid
int	v(int i, int j)
{
	if (getb()->map[i][j] == '0' || getb()->map[i][j] == 'N' || \
getb()->map[i][j] == 'S' || getb()->map[i][j] == 'E' || \
getb()->map[i][j] == 'W' || getb()->map[i][j] == '1')
		return (0);
	return (1);
}
