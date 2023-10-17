#include "cube.h"

static void check_wrong_char()
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (getb()->map[i] != NULL)
	{
		j = 0;
		while (getb()->map[i][j] != '\0')
		{
			c = getb()->map[i][j];
			if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != ' ')
				free_and_exit("Error: Invalid character in map.");
			j++;
		}
		i++;
	}
}

int is_player_or_zero(int i, int j)
{
	if (getb()->map[i][j] == '0' || getb()->map[i][j] == 'N' || getb()->map[i][j] == 'S' || getb()->map[i][j] == 'E' || getb()->map[i][j] == 'W')
		return (0);
	return (1);
}

// v for valid
int v(int i, int j)
{
	if (getb()->map[i][j] == '0' || getb()->map[i][j] == 'N' || getb()->map[i][j] == 'S' || getb()->map[i][j] == 'E' || getb()->map[i][j] == 'W' || getb()->map[i][j] == '1')
		return (0);
	return (1);
}

void check_first_last_lines()
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
	// if (getb()->map[j][i] == '\0')
	//	 j--;
	// printf("j: %d\n", j);
	while (getb()->map[j][i] != '\0')
	{
		if (getb()->map[j][i] != '1' && getb()->map[j][i] != ' ')
			free_and_exit("Error: Map is not closed/surrounded by walls.");
		i++;
	}
}

void check_walls()
{
	int	i;
	int	j;

	// if first or last line has is_player_or_zero char. Then exit
	check_first_last_lines();
	i = 0;
	while (getb()->map[i] != NULL)
	{
		j = 0;
		while (getb()->map[i][j] != '\0')
		{
			if (is_player_or_zero(i, j) == 0)
				if (v(i, j - 1) != 0 || v(i, j + 1) != 0 || v(i - 1, j) != 0 || v(i + 1, j) != 0)
					free_and_exit("Error: Map is not closed/surrounded by walls.");
			j++;
		}
		i++;
	}
}

static void check_newlines()
{
	int	i;

	i = 0;
	while (getb()->map_string[i + 1] != '\0')
	{
		if (getb()->map_string[i] == '\n' && getb()->map_string[i + 1] == '\n')
		{
			while (getb()->map_string[i] == '\n')
				i++;
			if (getb()->map_string[i] != '\0')
				free_and_exit("Error: Map can't be separated by a newline.");
		}
		i++;
	}
}

static void check_player()
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (getb()->map_string[i] != '\0')
	{
		if (getb()->map_string[i] == 'N' || getb()->map_string[i] == 'S' || getb()->map_string[i] == 'E' || getb()->map_string[i] == 'W')
		{
			if (flag == 1)
				free_and_exit("Error: Map has more than one player.");
			flag = 1;
		}
		i++;
	}
	if (!flag)
		free_and_exit("Error: Map doesn't have a player.");
}

void check_map()
{
	check_newlines();
	check_wrong_char();
	check_walls();
	check_player();
}
