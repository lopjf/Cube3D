/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:19:05 by loris             #+#    #+#             */
/*   Updated: 2023/12/15 19:19:06 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	insert(char **str, char *buf, int i, int skip)
{
	int	j;
	int	k;

	j = 0;
	if (ft_strncmp(*str, "\0", 1) == 0)
	{
		free(*str);
		*str = ft_strdup(buf + skip_spaces(buf, i + skip));
		if ((*str)[ft_strlen(*str) - 1] == '\n')
			(*str)[ft_strlen(*str) - 1] = '\0';
		while ((*str)[j] != ' ' && (*str)[j] != '\0')
			j++;
		k = skip_spaces(*str, j);
		if ((*str)[k] != '\0' && (*str)[k] != '\n')
			free_and_exit("Error: Space can't compose an element value.");
		(*str)[j] = '\0';
	}
	else
	{
		free(buf);
		free_and_exit("Error: An element is defined more than once.");
	}
}

static int	map_bool(char *buf)
{
	if (ft_strncmp(getb()->data.no_path, "\0", 1) != 0 && \
ft_strncmp(getb()->data.so_path, "\0", 1) != 0 && \
ft_strncmp(getb()->data.we_path, "\0", 1) != 0 && \
ft_strncmp(getb()->data.ea_path, "\0", 1) != 0 && \
ft_strncmp(getb()->data.f_path, "\0", 1) != 0 && \
ft_strncmp(getb()->data.c_path, "\0", 1) != 0)
		if (buf[0] == ' ' || buf[0] == '1')
			return (0);
	return (1);
}

// the || matters here to get a more precise error message when no_path is input
// else if (ft_strncmp((buf + i), "\n\0", 2) != 0) act like an else.
// But if (ft_strncmp((buf + i), "\n\0", 2) == 0), then do nothing.
static void	get_elements(char *buf, int i)
{
	i = skip_spaces(buf, 0);
	if (ft_strncmp((buf + i), "NO ", 3) == 0 || \
ft_strncmp((buf + i), "NO\n", 3) == 0)
		insert(&getb()->data.no_path, buf, i, 2);
	else if (ft_strncmp((buf + i), "SO ", 3) == 0 || \
ft_strncmp((buf + i), "SO\n", 3) == 0)
		insert(&getb()->data.so_path, buf, i, 2);
	else if (ft_strncmp((buf + i), "WE ", 3) == 0 || \
ft_strncmp((buf + i), "WE\n", 3) == 0)
		insert(&getb()->data.we_path, buf, i, 2);
	else if (ft_strncmp((buf + i), "EA ", 3) == 0 || \
ft_strncmp((buf + i), "EA\n", 3) == 0)
		insert(&getb()->data.ea_path, buf, i, 2);
	else if (ft_strncmp((buf + i), "F ", 2) == 0 || \
ft_strncmp((buf + i), "F\n", 3) == 0)
		insert(&getb()->data.f_path, buf, i, 1);
	else if (ft_strncmp((buf + i), "C ", 2) == 0 || \
ft_strncmp((buf + i), "C\n", 3) == 0)
		insert(&getb()->data.c_path, buf, i, 1);
	else if (ft_strncmp((buf + i), "\n\0", 2) != 0)
	{
		free(buf);
		free_and_exit("Error: Invalid element.");
	}
}

static char	*get_map_string(char *buf, int fd)
{
	char	*ret;
	char	*map;
	int		i;
	int		j;

	map = get_file(fd);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(map) + 1));
	if (!ret)
	{
		free(map);
		return (NULL);
	}
	i = cpy_ret(ret, buf);
	j = 0;
	while (map[j] != 0)
	{
		ret[i] = map[j];
		j++;
		i++;
	}
	ret[i] = '\0';
	free(map);
	return (ret);
}

void	parse(char *map_name, t_base *b, int fd, char *buf)
{
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return ;
	while (buf != NULL)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		if (map_bool(buf) != 0)
			get_elements(buf, 0);
		else
		{
			free(getb()->map_string);
			b->map_string = get_map_string(buf, fd);
			init_map_depth();
			init_map_width();
			free(getb()->map);
	b->map = ft_split(b->map_string, '\n');
		}
		free(buf);
	}
	close(fd);
	if (ft_strncmp(getb()->map_string, "\0", 1) == 0)
		free_and_exit("Error: There is no map.");
}
