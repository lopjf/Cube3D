#include "cube.h"

int	check_blocks(char *map, char *tmp)
{
	tmp = ft_strchr(map, 'E');
	if (!tmp)
		return (0);
	else
		if (ft_strchr(tmp + 1, 'E') != NULL)
			return (0);
	tmp = ft_strchr(map, 'P');
	if (!tmp)
		return (0);
	else
		if (ft_strchr(tmp + 1, 'P') != NULL)
			return (0);
	tmp = ft_strchr(map, 'C');
	if (!tmp)
		return (0);
	return (1);
}

int	check_rectangular(char *map, int x_lenght, int i)
{
	while (map[i] != '\n')
		if (map[i++] != '1')
			return (0);
	while (map[i])
	{
		if (map[i] == '\n')
			if (map[i - 1] != '1' || map[i + 1] != '1')
				return (0);
		i++;
	}
	while (map[i - x_lenght] != '\0')
	{
		if (map[i - x_lenght] != '1')
			return (0);
		i++;
	}
	i = x_lenght;
	while (map[x_lenght])
	{
		if (map[x_lenght] != '\n')
			return (0);
		x_lenght = x_lenght + i + 1;
	}
	return (1);
}

void	replace_zeros(char *copy, int x_lenght, int p)
{
	while (copy[p] != 'P')
		p++;
	if (copy[p - x_lenght] == '0' || copy[p - x_lenght] == 'C')
	{
		copy[p - x_lenght] = 'P';
		replace_zeros(copy, x_lenght, p - x_lenght);
	}
	if (copy[p + 1] == '0' || copy[p + 1] == 'C')
	{
		copy[p + 1] = 'P';
		replace_zeros(copy, x_lenght, p + 1);
	}
	if (copy[p + x_lenght] == '0' || copy[p + x_lenght] == 'C')
	{
		copy[p + x_lenght] = 'P';
		replace_zeros(copy, x_lenght, p + x_lenght);
	}
	if (copy[p - 1] == '0' || copy[p - 1] == 'C')
	{
		copy[p - 1] = 'P';
		replace_zeros(copy, x_lenght, p - 1);
	}
}

int	check_path(char *copy, int x, int i)
{
	replace_zeros(copy, x, 0);
	while (copy[i])
	{
		if (copy[i++] == 'C')
		{
			free(copy);
			return (0);
		}
	}
	i = 0;
	while (copy[i])
	{
		if (copy[i] == 'E')
		{
			if (copy[i - x] != 'P' && copy[i + 1] != 'P' && \
			copy[i + x] != 'P' && copy[i - 1] != 'P')
			{
				free(copy);
				return (0);
			}
		}
		i++;
	}
	free(copy);
	return (1);
}

int	check_valid_map(char *map)
{
	int	x_lenght;

	x_lenght = 0;
	while (map[x_lenght] != '\n' && map[x_lenght])
		x_lenght++;
	if (check_blocks(map, NULL) == 0)
	{
		ft_printf("Error\nThe map must must contain at least 1 exit, 1 collectible, and 1 starting\
 position. It can't contains a duplicates characters (exit/start)\n");
		return (0);
	}
	if (check_rectangular(map, x_lenght, 0) == 0)
	{
		ft_printf("Error\nThe map must be rectangular and surrounded by walls\n");
		return (0);
	}
	if (check_path(ft_strdup(map), x_lenght + 1, 0) == 0)
	{
		ft_printf("Error\nThe map doesn't have a valid path\n");
		return (0);
	}
	return (1);
}
