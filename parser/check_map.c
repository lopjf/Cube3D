/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:18:55 by loris             #+#    #+#             */
/*   Updated: 2023/12/15 19:18:56 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	check_wrong_char(void)
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
			if (c != '0' && c != '1' && c != 'N' && \
c != 'S' && c != 'E' && c != 'W' && c != ' ')
				free_and_exit("Error: Invalid character in map.");
			j++;
		}
		i++;
	}
}

// if first or last line has is_player_or_zero char. Then exit
//	v for valid
static void	check_walls(void)
{
	int	i;
	int	j;

	check_first_last_lines();
	i = 0;
	while (getb()->map[i] != NULL)
	{
		j = 0;
		while (getb()->map[i][j] != '\0')
		{
			if (is_player_or_zero(i, j) == 0)
				if (v(i, j - 1) != 0 || v(i, j + 1) != 0 || \
v(i - 1, j) != 0 || v(i + 1, j) != 0)
					free_and_exit("Error: Map is not \
closed/surrounded by walls.");
			j++;
		}
		i++;
	}
}

static void	check_newlines(void)
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

static void	check_player(void)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (getb()->map_string[i] != '\0')
	{
		if (getb()->map_string[i] == 'N' || getb()->map_string[i] == 'S' || \
getb()->map_string[i] == 'E' || getb()->map_string[i] == 'W')
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

void	check_map(void)
{
	check_newlines();
	check_wrong_char();
	check_walls();
	check_player();
}
